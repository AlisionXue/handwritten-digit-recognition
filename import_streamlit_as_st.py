import streamlit as st
import cv2
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout, BatchNormalization
from tensorflow.keras.datasets import mnist
from sklearn.metrics import confusion_matrix
import seaborn as sns

# Data Preprocessing
def preprocess_image(img):
    """Convert image to grayscale and apply edge detection"""
    if len(img.shape) == 3:
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    else:
        gray = img  # Already grayscale
    edges = cv2.Sobel(gray, cv2.CV_64F, 1, 0, ksize=3)
    return edges

# Load and preprocess MNIST dataset
@st.cache
def load_and_preprocess_data():
    (x_train, y_train), (x_test, y_test) = mnist.load_data()
    x_train_processed = np.array([preprocess_image(img) for img in x_train[:1000]]).reshape(-1, 28, 28, 1) / 255.0
    x_test_processed = np.array([preprocess_image(img) for img in x_test[:200]]).reshape(-1, 28, 28, 1) / 255.0
    return x_train_processed, y_train[:1000], x_test_processed, y_test[:200]

# Define the model
@st.cache(allow_output_mutation=True)
def create_model():
    model = Sequential([
        Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
        BatchNormalization(),
        MaxPooling2D((2, 2)),
        Conv2D(64, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D((2, 2)),
        Conv2D(128, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D((2, 2)),
        Flatten(),
        Dense(128, activation='relu'),
        Dropout(0.5),
        Dense(10, activation='softmax')
    ])
    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
    return model

# Main Streamlit app
st.title("Handwritten Digit Recognition")
st.write("This app recognizes handwritten digits using a CNN model trained on the MNIST dataset.")

x_train, y_train, x_test, y_test = load_and_preprocess_data()
model = create_model()

# Select test method
option = st.selectbox("Choose a testing method:", ["Use preloaded dataset images", "Upload your own image"])

if option == "Use preloaded dataset images":
    st.write("Testing with preloaded MNIST dataset images:")
    for i in range(10):
        image = x_test[i]
        prediction = np.argmax(model.predict(np.expand_dims(image / 255.0, axis=[0, -1])))
        st.image(image, caption=f"Predicted Digit: {prediction}", use_column_width=True)

elif option == "Upload your own image":
    uploaded_file = st.file_uploader("Upload a handwritten digit image (28x28 grayscale)", type=["jpg", "png", "jpeg"])
    if uploaded_file is not None:
        file_bytes = np.asarray(bytearray(uploaded_file.read()), dtype=np.uint8)
        image = cv2.imdecode(file_bytes, cv2.IMREAD_GRAYSCALE)
        image_resized = cv2.resize(image, (28, 28)) / 255.0
        image_processed = np.expand_dims(image_resized, axis=[0, -1])
        prediction = np.argmax(model.predict(image_processed))
        st.image(image, caption=f"Predicted Digit: {prediction}", use_column_width=True)

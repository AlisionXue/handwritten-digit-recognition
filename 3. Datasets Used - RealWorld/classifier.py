import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, f1_score
import tensorflow as tf
import matplotlib.pyplot as plt

# Load dataset from URL
URL = "https://archive.ics.uci.edu/ml/machine-learning-databases/spambase/spambase.data"
data = pd.read_csv(URL, header=None)

# Data preparation
X = data.drop(data.columns[-1], axis=1)  # Features
y = data[data.columns[-1]]  # Target

# Split data into training, validation, and test sets
X_train_val, X_test, y_train_val, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
X_train, X_val, y_train, y_val = train_test_split(X_train_val, y_train_val, test_size=0.25, random_state=42)

# Reshape inputs for CNN
timesteps = 1
X_train = X_train.values.reshape((X_train.shape[0], timesteps, X_train.shape[1]))
X_val = X_val.values.reshape((X_val.shape[0], timesteps, X_val.shape[1]))
X_test = X_test.values.reshape((X_test.shape[0], timesteps, X_test.shape[1]))

# Build CNN model with modified kernel size
model = tf.keras.Sequential([
    tf.keras.layers.Conv1D(filters=64, kernel_size=1, activation='relu', input_shape=(timesteps, X_train.shape[2])),
    tf.keras.layers.MaxPooling1D(pool_size=1),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(50, activation='relu'),
    tf.keras.layers.Dense(1, activation='sigmoid')
])


# Compile model
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Train model
history = model.fit(X_train, y_train, epochs=10, batch_size=32, validation_data=(X_val, y_val), verbose=1)

# Evaluate model on validation set
val_loss, val_accuracy = model.evaluate(X_val, y_val)
print(f'Validation Accuracy: {val_accuracy}')

# Evaluate model on test set
test_loss, test_accuracy = model.evaluate(X_test, y_test)
print(f'Test Accuracy: {test_accuracy}')

# Plot training & validation loss
plt.plot(history.history['loss'], label='Train Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title('Model Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
plt.show()

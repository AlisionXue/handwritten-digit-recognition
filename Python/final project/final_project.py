import preprocess
from model import create_improved_model as create_model
import matplotlib.pyplot as plt
from tensorflow.keras.datasets import mnist  
import numpy as np

(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train_processed = [preprocess.preprocess_image(img) for img in x_train[:1000]]  # 只取部分数据示例
x_test_processed = [preprocess.preprocess_image(img) for img in x_test[:200]]

x_train_processed = np.array(x_train_processed).reshape(-1, 28, 28, 1) / 255.0
x_test_processed = np.array(x_test_processed).reshape(-1, 28, 28, 1) / 255.0

model = create_model()

history = model.fit(x_train_processed, y_train[:1000], epochs=5, batch_size=32, validation_split=0.2)

test_loss, test_acc = model.evaluate(x_test_processed, y_test[:200])
print(f"Test Accuracy: {test_acc:.2f}")

plt.figure(figsize=(12, 4))

plt.subplot(1, 2, 1)
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title('Loss Over Epochs')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()


plt.subplot(1, 2, 2)
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.title('Accuracy Over Epochs')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.legend()

plt.tight_layout()
plt.show()


for i in range(10):
    plt.imshow(x_test_processed[i].reshape(28, 28), cmap='gray')
    plt.title(f"True: {y_test[i]}, Predicted: {np.argmax(model.predict(x_test_processed[i:i+1]))}")
    plt.show()

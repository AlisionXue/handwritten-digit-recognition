import pandas as pd
import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, f1_score
import matplotlib.pyplot as plt

# 从URL加载数据集
URL = "https://archive.ics.uci.edu/ml/machine-learning-databases/spambase/spambase.data"
data = pd.read_csv(URL, header=None)

# 数据准备
X = data.drop(data.columns[-1], axis=1).values  # 特征
y = data[data.columns[-1]].values  # 目标

# 将数据拆分为训练集、验证集和测试集
X_train_val, X_test, y_train_val, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
X_train, X_val, y_train, y_val = train_test_split(X_train_val, y_train_val, test_size=0.25, random_state=42)

# 确保特征数可以被时间步数整除
feature_count = X_train.shape[1]
timesteps = 5

# 如果特征数不能被时间步数整除，则调整时间步数
if feature_count % timesteps != 0:
    timesteps = feature_count

X_train = X_train.reshape((X_train.shape[0], timesteps, feature_count // timesteps))
X_val = X_val.reshape((X_val.shape[0], timesteps, feature_count // timesteps))
X_test = X_test.reshape((X_test.shape[0], timesteps, feature_count // timesteps))


# 构建 DeepConvLSTM 模型
model = tf.keras.Sequential([
    tf.keras.layers.Conv1D(filters=64, kernel_size=2, activation='relu', input_shape=(X_train.shape[1], X_train.shape[2])),
    tf.keras.layers.MaxPooling1D(pool_size=1),  # 或者去掉池化层以避免尺寸过小
    tf.keras.layers.LSTM(50, return_sequences=True),
    tf.keras.layers.LSTM(50),
    tf.keras.layers.Dense(1, activation='sigmoid')
])

# 编译模型
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# 训练模型
history = model.fit(X_train, y_train, epochs=10, batch_size=32, validation_data=(X_val, y_val), verbose=1)

# 在测试集上评估模型性能
y_test_pred = (model.predict(X_test) > 0.5).astype("int32")
test_accuracy = accuracy_score(y_test, y_test_pred)
test_f1 = f1_score(y_test, y_test_pred, average='macro')

print(f'Test Accuracy: {test_accuracy}')
print(f'Test Macro F1 Score: {test_f1}')

# 绘制训练和验证损失
plt.plot(history.history['loss'], label='Train Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title('Model Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
plt.show()

import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, f1_score
import matplotlib.pyplot as plt

# 从URL加载数据集
URL = "https://archive.ics.uci.edu/ml/machine-learning-databases/spambase/spambase.data"
data = pd.read_csv(URL, header=None)

# 数据准备
X = data.drop(data.columns[-1], axis=1)  # 特征
y = data[data.columns[-1]]  # 目标

# 将数据拆分为训练集、验证集和测试集
results = []
for i in range(5):
    print(f"Experiment {i+1} Results:")
    X_train_val, X_test, y_train_val, y_test = train_test_split(X, y, test_size=0.2, random_state=42+i)
    X_train, X_val, y_train, y_val = train_test_split(X_train_val, y_train_val, test_size=0.25, random_state=42+i)

    # 模型实现
    rf_model = RandomForestClassifier(n_estimators=100, random_state=42)

    # 模型训练
    rf_model.fit(X_train, y_train)

    # 模型评估
    y_pred = rf_model.predict(X_val)
    accuracy = accuracy_score(y_val, y_pred)
    f1 = f1_score(y_val, y_pred, average='macro')

    print(f'Validation Accuracy: {accuracy}')
    print(f'Validation Macro F1 Score: {f1}')

    # 最终在测试集上评估模型性能
    y_test_pred = rf_model.predict(X_test)
    test_accuracy = accuracy_score(y_test, y_test_pred)
    test_f1 = f1_score(y_test, y_test_pred, average='macro')

    print(f'Test Accuracy: {test_accuracy}')
    print(f'Test Macro F1 Score: {test_f1}')

    results.append({
        'Experiment': i + 1,
        'Validation Accuracy': accuracy,
        'Validation Macro F1 Score': f1,
        'Test Accuracy': test_accuracy,
        'Test Macro F1 Score': test_f1
    })

# 结果绘图
fig, axs = plt.subplots(1, 2, figsize=(12, 5))
fig.suptitle('Random Forest Experiment Results')

# 绘制验证集的结果
val_acc = [res['Validation Accuracy'] for res in results]
val_f1 = [res['Validation Macro F1 Score'] for res in results]
axs[0].plot(range(1, 6), val_acc, marker='o', label='Validation Accuracy')
axs[0].plot(range(1, 6), val_f1, marker='o', linestyle='--', label='Validation Macro F1 Score')
axs[0].set_xticks(range(1, 6))  # 修复 x 轴刻度
axs[0].set_title('Validation Set Results')
axs[0].set_xlabel('Experiment Number')
axs[0].set_ylabel('Score')
axs[0].legend()

# 绘制测试集的结果
test_acc = [res['Test Accuracy'] for res in results]
test_f1 = [res['Test Macro F1 Score'] for res in results]
axs[1].plot(range(1, 6), test_acc, marker='o', label='Test Accuracy')
axs[1].plot(range(1, 6), test_f1, marker='o', linestyle='--', label='Test Macro F1 Score')
axs[1].set_xticks(range(1, 6))  # 修复 x 轴刻度
axs[1].set_title('Test Set Results')
axs[1].set_xlabel('Experiment Number')
axs[1].set_ylabel('Score')
axs[1].legend()

plt.tight_layout()
plt.subplots_adjust(top=0.85)
plt.show()
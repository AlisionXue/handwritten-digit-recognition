import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split


real_data = pd.read_csv("real_data.csv")
virtual_data = pd.read_csv("imu_data.csv")

X = pd.concat([real_data.drop('label', axis=1), virtual_data.drop('label', axis=1)])
y = pd.concat([real_data['label'], virtual_data['label']])


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)


clf = RandomForestClassifier()
clf.fit(X_train, y_train)
print("模型准确率:", clf.score(X_test, y_test))


import numpy as np
import pandas as pd
import os
from scipy.io import loadmat
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, f1_score
import matplotlib.pyplot as plt

# Define path to the USC-HAD dataset directory
dataset_path = "D:/USC-HAD/"

# Function to read and load a .mat file
def load_mat_file(filepath):
    data = loadmat(filepath)
    # Extract accelerometer and gyroscope readings, assuming these keys
    acc = data['acc']  # Shape (samples, 3) for x, y, z accelerometer
    gyro = data['gyro']  # Shape (samples, 3) for x, y, z gyroscope
    activity_id = data['activity'][0][0]  # Assuming the activity ID is stored like this
    combined_data = np.hstack((acc, gyro))  # Combine accelerometer and gyroscope data
    return combined_data, activity_id

# Load all .mat files from each subject folder
X_list = []
y_list = []
for subject_folder in os.listdir(dataset_path):
    subject_path = os.path.join(dataset_path, subject_folder)
    if os.path.isdir(subject_path):
        mat_files = [os.path.join(subject_path, f) for f in os.listdir(subject_path) if f.endswith('.mat')]
        for file in mat_files:
            X_data, y_data = load_mat_file(file)
            X_list.append(X_data)
            y_list.append(np.full((X_data.shape[0],), y_data))  # Create an array with activity ID for each sample

# Concatenate all data
X = np.vstack(X_list)
y = np.hstack(y_list)

# Split data into training, validation, and test sets
X_train_val, X_test, y_train_val, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
X_train, X_val, y_train, y_val = train_test_split(X_train_val, y_train_val, test_size=0.25, random_state=42)

# Model implementation
rf_model = RandomForestClassifier(n_estimators=100, random_state=42)

# Model training
rf_model.fit(X_train, y_train)

# Model evaluation on validation set
y_val_pred = rf_model.predict(X_val)
val_accuracy = accuracy_score(y_val, y_val_pred)
val_f1 = f1_score(y_val, y_val_pred, average='macro')
print(f'Validation Accuracy: {val_accuracy}')
print(f'Validation Macro F1 Score: {val_f1}')

# Final evaluation on test set
y_test_pred = rf_model.predict(X_test)
test_accuracy = accuracy_score(y_test, y_test_pred)
test_f1 = f1_score(y_test, y_test_pred, average='macro')
print(f'Test Accuracy: {test_accuracy}')
print(f'Test Macro F1 Score: {test_f1}')

# Plot Results
results = {
    'Set': ['Validation', 'Test'],
    'Accuracy': [val_accuracy, test_accuracy],
    'Macro F1 Score': [val_f1, test_f1]
}
results_df = pd.DataFrame(results)

fig, ax = plt.subplots(figsize=(10, 6))
ax.plot(results_df['Set'], results_df['Accuracy'], marker='o', label='Accuracy')
ax.plot(results_df['Set'], results_df['Macro F1 Score'], marker='o', linestyle='--', label='Macro F1 Score')
ax.set_title('USC-HAD Experiment Results')
ax.set_xlabel('Data Set')
ax.set_ylabel('Score')
ax.legend()
plt.show()

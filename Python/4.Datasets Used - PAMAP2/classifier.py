import pandas as pd
import numpy as np
import os

# Define path to the dataset directory (Protocol and Optional)
protocol_dataset_path = "D:/PAMAP2_Dataset/Protocol"
optional_dataset_path = "D:/PAMAP2_Dataset/Optional"

# Load all the .dat files from both directories
protocol_files = [os.path.join(protocol_dataset_path, f) for f in os.listdir(protocol_dataset_path) if f.endswith('.dat')]
optional_files = [os.path.join(optional_dataset_path, f) for f in os.listdir(optional_dataset_path) if f.endswith('.dat')]

# Combine all files into a single list
data_files = protocol_files + optional_files

# Function to read a single .dat file
def load_dat_file(filepath):
    # Define column names based on the documentation of the dataset
    column_names = ['timestamp', 'activityID', 'heart_rate'] + [f'imu{idx}' for idx in range(1, 52)]
    data = pd.read_csv(filepath, sep=' ', header=None, names=column_names, na_values='NaN')
    return data

# Load data from all subjects
all_data = pd.concat([load_dat_file(file) for file in data_files])

# Fill missing values using the mean of each column
all_data.fillna(all_data.mean(), inplace=True)

# Filter by specific activity IDs to increase data
activity_ids = list(range(1, 19))  # Include all 18 activity IDs
filtered_data = all_data[all_data['activityID'].isin(activity_ids)]

# Extract features and target
X = filtered_data.iloc[:, 2:]  # Using heart rate and IMU data as features
y = filtered_data['activityID']

# Check if the dataset is large enough
if len(X) < 10:  # Reduced the threshold for minimum samples
    print("Not enough data to split into training, validation, and test sets.")
else:
    # Split into training, validation, and test sets
    from sklearn.model_selection import train_test_split

    # Reduce the test size to ensure enough data for training
    X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.1, random_state=42)
    X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

    # Model training and evaluation
    from sklearn.ensemble import RandomForestClassifier
    from sklearn.metrics import accuracy_score, f1_score
    import matplotlib.pyplot as plt

    results = []

    for i in range(5):
        print(f"Experiment {i+1} Results:")

        # Model implementation
        rf_model = RandomForestClassifier(n_estimators=10, max_depth=5, random_state=42+i)

        print("Training the model...")
        # Model training
        rf_model.fit(X_train, y_train)

        print("Model trained. Evaluating on validation set...")
        # Validation set evaluation
        y_pred = rf_model.predict(X_val)
        val_accuracy = accuracy_score(y_val, y_pred)
        val_f1 = f1_score(y_val, y_pred, average='macro')

        print(f'Validation Accuracy: {val_accuracy}')
        print(f'Validation Macro F1 Score: {val_f1}')

        print("Evaluating on test set...")
        # Test set evaluation
        y_test_pred = rf_model.predict(X_test)
        test_accuracy = accuracy_score(y_test, y_test_pred)
        test_f1 = f1_score(y_test, y_test_pred, average='macro')

        print(f'Test Accuracy: {test_accuracy}')
        print(f'Test Macro F1 Score: {test_f1}')

        results.append({
            'Experiment': i + 1,
            'Validation Accuracy': val_accuracy,
            'Validation Macro F1 Score': val_f1,
            'Test Accuracy': test_accuracy,
            'Test Macro F1 Score': test_f1
        })

    # Plotting the results
    fig, axs = plt.subplots(1, 2, figsize=(12, 5))
    fig.suptitle('Random Forest Experiment Results')

    # Plot validation set results
    val_acc = [res['Validation Accuracy'] for res in results]
    val_f1 = [res['Validation Macro F1 Score'] for res in results]
    axs[0].plot(range(1, 6), val_acc, marker='o', label='Validation Accuracy')
    axs[0].plot(range(1, 6), val_f1, marker='o', linestyle='--', label='Validation Macro F1 Score')
    axs[0].set_xticks(range(1, 6))
    axs[0].set_title('Validation Set Results')
    axs[0].set_xlabel('Experiment Number')
    axs[0].set_ylabel('Score')
    axs[0].legend()

    # Plot test set results
    test_acc = [res['Test Accuracy'] for res in results]
    test_f1 = [res['Test Macro F1 Score'] for res in results]
    axs[1].plot(range(1, 6), test_acc, marker='o', label='Test Accuracy')
    axs[1].plot(range(1, 6), test_f1, marker='o', linestyle='--', label='Test Macro F1 Score')
    axs[1].set_xticks(range(1, 6))
    axs[1].set_title('Test Set Results')
    axs[1].set_xlabel('Experiment Number')
    axs[1].set_ylabel('Score')
    axs[1].legend()

    plt.tight_layout()
    plt.subplots_adjust(top=0.85)
    plt.show()

    input("Press Enter to continue...")  # Added to prevent the program from closing immediately

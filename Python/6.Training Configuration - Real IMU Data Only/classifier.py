import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import f1_score
from sklearn.model_selection import train_test_split, cross_val_score
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense, Conv1D, MaxPooling1D, Flatten
import requests
from io import StringIO

# Step 1: Load the IMU Dataset
# Load real IMU dataset from online link
url_real = 'https://archive.ics.uci.edu/ml/machine-learning-databases/00231/PAMAP2_Dataset/Protocol/subject101.dat'
response_real = requests.get(url_real)
df_real = pd.read_csv(StringIO(response_real.text), sep='\s+', header=None)

# Assign all column names to the PAMAP2 dataset (54 columns)
column_names = [
    'timestamp', 'activity_id', 'heart_rate',
    'hand_temp', 'hand_acc_x', 'hand_acc_y', 'hand_acc_z',
    'hand_gyro_x', 'hand_gyro_y', 'hand_gyro_z',
    'hand_mag_x', 'hand_mag_y', 'hand_mag_z',
    'chest_temp', 'chest_acc_x', 'chest_acc_y', 'chest_acc_z',
    'chest_gyro_x', 'chest_gyro_y', 'chest_gyro_z',
    'chest_mag_x', 'chest_mag_y', 'chest_mag_z',
    'ankle_temp', 'ankle_acc_x', 'ankle_acc_y', 'ankle_acc_z',
    'ankle_gyro_x', 'ankle_gyro_y', 'ankle_gyro_z',
    'ankle_mag_x', 'ankle_mag_y', 'ankle_mag_z'
]
df_real.columns = column_names[:df_real.shape[1]]

# Step 2: Preprocess the Data
# Standardize column names to avoid mismatch due to hidden characters
df_real.columns = df_real.columns.str.strip().str.lower()

# Check if required columns exist before extraction
required_columns = {'hand_acc_x', 'hand_acc_y', 'hand_acc_z', 'activity_id'}
missing_columns = required_columns - set(df_real.columns)
if missing_columns:
    raise ValueError(f"Missing columns in the dataset: {missing_columns}")

# Extract only the hand accelerometer data and the activity label
df_real = df_real[['hand_acc_x', 'hand_acc_y', 'hand_acc_z', 'activity_id']].dropna()

# Extract features and labels
X = df_real[['hand_acc_x', 'hand_acc_y', 'hand_acc_z']].values
y = df_real['activity_id'].values

# Split data into training, validation, and test sets
X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.3, random_state=42)
X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

# Step 3: Train Random Forest Classifier
rf_classifier = RandomForestClassifier(n_estimators=100, random_state=42)
rf_classifier.fit(X_train, y_train)

# Step 4: Evaluate the Random Forest Model
y_pred_rf = rf_classifier.predict(X_val)
macro_f1_rf = f1_score(y_val, y_pred_rf, average='macro')
print(f"Random Forest Macro F1 Score on Validation Set: {macro_f1_rf}")

# Step 5: Train DeepConvLSTM Model
# Reshape data for LSTM [samples, timesteps, features]
X_train_lstm = X_train.reshape((X_train.shape[0], 1, X_train.shape[1]))
X_val_lstm = X_val.reshape((X_val.shape[0], 1, X_val.shape[1]))
X_test_lstm = X_test.reshape((X_test.shape[0], 1, X_test.shape[1]))

# Build DeepConvLSTM model
model = Sequential()
model.add(Conv1D(filters=64, kernel_size=2, activation='relu', input_shape=(X_train_lstm.shape[1], X_train_lstm.shape[2])))
model.add(MaxPooling1D(pool_size=2))
model.add(LSTM(50, activation='relu'))
model.add(Flatten())
model.add(Dense(1, activation='softmax'))

model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Train the model
model.fit(X_train_lstm, y_train, validation_data=(X_val_lstm, y_val), epochs=10, batch_size=32, verbose=1)

# Step 6: Evaluate the DeepConvLSTM Model on Test Set
loss, accuracy = model.evaluate(X_test_lstm, y_test, verbose=0)
print(f"DeepConvLSTM Accuracy on Test Set: {accuracy}")

# Predict and calculate F1 score
y_pred_lstm = model.predict(X_test_lstm)
y_pred_lstm_classes = np.argmax(y_pred_lstm, axis=1)
macro_f1_lstm = f1_score(y_test, y_pred_lstm_classes, average='macro')
print(f"DeepConvLSTM Macro F1 Score on Test Set: {macro_f1_lstm}")

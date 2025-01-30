import os
import pandas as pd
import numpy as np

# Define the path to the dataset root folder (adjust this path as necessary)
dataset_root = 'D:/realworld2016_dataset'
virtual_data_root = 'path/to/virtual_dataset'

# Load sensor data from RealWorld dataset
def load_realworld_data(proband_list=['proband1', 'proband2', 'proband3'], activities=['walking', 'running', 'sitting']):
    all_data = []
    labels = []
    
    # Loop through each proband folder
    for proband in proband_list:
        proband_path = os.path.join(dataset_root, proband, 'data')
        
        # Loop through each activity file that we want to use
        for activity in activities:
            activity_file = os.path.join(proband_path, f'{activity}.csv')
            if os.path.exists(activity_file):
                # Load the CSV file into a DataFrame
                df = pd.read_csv(activity_file)
                all_data.append(df)
                labels.extend([activity] * len(df))
            else:
                print(f"Warning: {activity_file} does not exist")
    
    # Concatenate all data and labels into single DataFrame and array
    combined_data = pd.concat(all_data, axis=0)
    labels = np.array(labels)
    return combined_data, labels

# Load virtual sensor data
def load_virtual_data(activities=['walking', 'running', 'sitting']):
    all_data = []
    labels = []
    
    # Loop through each activity file that we want to use
    for activity in activities:
        activity_file = os.path.join(virtual_data_root, f'{activity}.csv')
        if os.path.exists(activity_file):
            # Load the CSV file into a DataFrame
            df = pd.read_csv(activity_file)
            all_data.append(df)
            labels.extend([activity] * len(df))
        else:
            print(f"Warning: {activity_file} does not exist")
    
    # Concatenate all data and labels into single DataFrame and array
    combined_data = pd.concat(all_data, axis=0)
    labels = np.array(labels)
    return combined_data, labels

# Combine real and virtual data
def combine_real_and_virtual_data(real_data, real_labels, virtual_data, virtual_labels):
    combined_data = pd.concat([real_data, virtual_data], axis=0).reset_index(drop=True)
    combined_labels = np.concatenate([real_labels, virtual_labels])
    return combined_data, combined_labels

# Example usage
if __name__ == "__main__":
    # Load RealWorld data
    real_data, real_labels = load_realworld_data()
    
    # Load Virtual data
    virtual_data, virtual_labels = load_virtual_data()
    
    # Combine RealWorld and Virtual data
    combined_data, combined_labels = combine_real_and_virtual_data(real_data, real_labels, virtual_data, virtual_labels)
    
    # Display first few rows of combined data
    print(combined_data.head())
    print(combined_labels[:10])

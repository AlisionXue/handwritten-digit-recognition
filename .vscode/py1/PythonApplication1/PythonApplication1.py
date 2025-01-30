import csv

def main():
    file_path = r'D:\HuaweiMoveData\Users\jack\Desktop\yob1990.csv'  # ensure it's come from corrrect
    
    # list male name
    male_names_1990 = []
    
    # open scv file
    try:
        with open(file_path, mode='r') as file:  # 注意这里定义了 'file'
            reader = csv.reader(file)
            
            # walk every level
            for row in reader:
                name, gender, count = row[0], row[1], int(row[2])
                
                # only choose male name
                if gender == 'M':
                    male_names_1990.append((name, count))
        
        # from a-z using name,only ten names
        male_names_1990.sort(key=lambda x: x[1], reverse=True)
        top_10_male_names = male_names_1990[:10]

        # print result
        print("The 10 most popular male names in 1990 are:")
        for i, (name, count) in enumerate(top_10_male_names, 1):
            print(f"{i}. {name} ({count} births)")

    except FileNotFoundError:
        print(f"Error: The file {file_path} was not found.")
    except UnicodeDecodeError:
        print(f"Error: There was an issue decoding the file {file_path}. Please check the file encoding.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()

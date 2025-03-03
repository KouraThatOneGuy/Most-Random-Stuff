import os
import shutil

def organize_files_by_type(directory):
    if not os.path.exists(directory):
        print("The specified directory does not exist.")
        return

    for filename in os.listdir(directory):
        if os.path.isfile(os.path.join(directory, filename)):
            file_extension = filename.split('.')[-1]
            folder_name = os.path.join(directory, file_extension)

            if not os.path.exists(folder_name):
                os.makedirs(folder_name)

            shutil.move(os.path.join(directory, filename), os.path.join(folder_name, filename))

# Specify the directory you want to organize
directory_path = "C:/path/to/your/directory"
organize_files_by_type(directory_path)

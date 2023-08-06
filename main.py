import os

current_file_path = os.path.abspath(__file__)
current_directory = os.path.dirname(current_file_path)
os.chdir(current_directory)

cwd = os.getcwd()

folders = [folder for folder in os.listdir(cwd) if os.path.isdir(os.path.join(cwd,folder))]

all_files = []

for folder in folders:
    
    folder_path = os.path.join(cwd,folder)
    all_files.append([file for file in os.listdir(folder_path)])

common_files = [file for file in set.intersection(*[set(files) for files in all_files])]

for file in common_files:
    print(file, end='\t')

    f = open(os.path.join(cwd,folders[0],file), 'r')
    print(f.read())
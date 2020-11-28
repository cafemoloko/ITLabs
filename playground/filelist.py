import glob
import os

try:
    path = input('Paste path to folder: ')
    os.chdir(path)
    files = glob.glob('*')

    with open('filelist.txt', 'w') as f:
        for file in files:
            f.write(file)
            f.write('\n')

except FileNotFoundError:
    print('Wrong path!')


       
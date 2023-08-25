import glob, os, re

path = input('Paste path to folder: ')
os.chdir(path)
files = glob.glob('*')
print(f'files loaded: {len(files)}')

filenames = '\n'.join([str(elem) for elem in files])
#                       doc no                       |   rev |     is |    |(            )| remove  | extension      
pattern = re.compile(r'(\w-[A-Z]+-[A-Z]+-[A-Z]+-[0-9]+_[A-Z0-9]+_[A-Z]+)(\s)(\([^A-Za-z]+)(-[0-9]+)(.[A-za-z]+)')

cropped_word = pattern.sub(r'\1\5', filenames)
print(f'cropped: {cropped_word}')


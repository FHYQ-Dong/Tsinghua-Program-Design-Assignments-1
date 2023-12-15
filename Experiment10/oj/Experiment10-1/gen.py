import subprocess
import os.path

os.chdir(os.path.dirname(os.path.abspath(__file__))) 

INPUTS = [
    "",
    "abcdefghc*exyzcferpk\nc?e",
    "wioeu4r2i;4ehn;hqi342ih\n?i",
    "OEUYUR#H*(Wrwdjksv\n#??*",
    "111111111111111\n11?1?1",
    "3quroi3\n3?",
]

for i in range(1, 6):
    with open(str(i) + '.in', 'w') as f:
        f.write(INPUTS[i])
    with open(str(i) + '.out', 'w') as f:
        f.write(subprocess.check_output(r"./Experiment10-1.exe", input=INPUTS[i].encode()).decode().replace('\r\n', '\n'))
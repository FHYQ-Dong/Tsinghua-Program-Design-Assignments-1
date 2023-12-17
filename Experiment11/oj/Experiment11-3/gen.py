import subprocess
import os.path

os.chdir(os.path.dirname(os.path.abspath(__file__))) 

INPUTS = [
    "",
    "10 9 8 7 6 5 4 3 2 1",
    "1 10 2 9 3 8 4 7 5 6",
    "6 7 8 9 10 5 4 3 2 1",
    "1 2 3 4 5 6 7 8 9 10",
    "6 3 7 8 2 5 10 1 9 4"
]

for i in range(1, 6):
    with open(str(i) + '.in', 'w') as f:
        f.write(INPUTS[i])
    with open(str(i) + '.out', 'w') as f:
        f.write(subprocess.check_output(r"./Experiment11-3.exe", input=INPUTS[i].encode()).decode().replace('\r\n', '\n'))
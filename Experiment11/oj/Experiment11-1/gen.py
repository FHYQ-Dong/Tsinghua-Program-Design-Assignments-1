import subprocess
import os.path

os.chdir(os.path.dirname(os.path.abspath(__file__))) 

INPUTS = [
    "",
    "1 12 3 14 5 16 7 18 9 20\n10 19 8 17 6 15 4 13 2 11",
    "1 3 5 7 9 11 13 15 17 19\n2 4 6 8 10 12 14 16 18 20",
    "1 1 1 1 1 1 1 1 1 1\n2 2 2 2 2 2 2 2 2 2",
    "1 2 3 4 5 6 7 8 9 10\n10 9 8 7 6 5 4 3 2 1",
    "1 2 3 4 5 6 7 8 9 10\n1 2 3 4 5 6 7 8 9 10"
]

for i in range(1, 6):
    with open(str(i) + '.in', 'w') as f:
        f.write(INPUTS[i])
    with open(str(i) + '.out', 'w') as f:
        f.write(subprocess.check_output(r"./Experiment11-1.exe", input=INPUTS[i].encode()).decode().replace('\r\n', '\n'))
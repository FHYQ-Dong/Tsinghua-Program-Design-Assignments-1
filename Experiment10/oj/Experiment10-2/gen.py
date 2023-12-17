import subprocess
import os.path

os.chdir(os.path.dirname(os.path.abspath(__file__))) 

INPUTS = [
    "",
    "aeiou",
    "ewoyurekadhkwrjscvwew",
    "oqekfhvjfsvnsa",
    "aaaaaaaaaaaaaaa",
    "andsjklvhseruiohwfvnbjf"
]

for i in range(1, 6):
    with open(str(i) + '.in', 'w') as f:
        f.write(INPUTS[i])
    with open(str(i) + '.out', 'w') as f:
        f.write(subprocess.check_output(r"./Experiment10-2.exe", input=INPUTS[i].encode()).decode().replace('\r\n', '\n'))
import subprocess
import os.path

os.chdir(os.path.dirname(os.path.abspath(__file__))) 

INPUTS = [
    "",
    "192.168.1.1",
    "1.1.1.1",
    "127.0.0.1",
    "10.0.0.1",
    "172.18.0.1"
]

for i in range(1, 6):
    with open(str(i) + '.in', 'w') as f:
        f.write(INPUTS[i])
    with open(str(i) + '.out', 'w') as f:
        f.write(subprocess.check_output(r"./Optional-Experiment10-2.exe", input=INPUTS[i].encode()).decode().replace('\r\n', '\n'))
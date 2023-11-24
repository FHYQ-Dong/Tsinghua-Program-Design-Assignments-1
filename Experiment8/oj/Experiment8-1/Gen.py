import os
import subprocess
import random
import time
exe_path = r'./ans.exe'
__path__ = os.path.dirname(os.path.abspath(__file__))
random.seed(time.time())
for i in range(1, 11):
    Input = str(random.randint(5, 5000))
    open(os.path.join(__path__, str(i) + '.in'), 'w').write(Input)
    Output = subprocess.check_output(os.path.join(__path__, exe_path), input=Input.encode()).decode()
    Output = Output.replace('\r', '').replace('\n', '')
    open(os.path.join(__path__, str(i) + '.out'), 'w').write(Output)
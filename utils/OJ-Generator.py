from sys import argv
from loguru import logger
import subprocess
import os.path
import json

class OjGenerator():
    def __init__(self, directory) -> None:
        self.directory = directory
        try:
            self.configFile = open(os.path.join(directory, 'Project.json'), 'r', encoding='utf-8')
            self.confargv = json.load(self.configFile)
            self.configFile.close()
        except:
            logger.error('Project.json not found.')
            exit(1)
        if not os.path.isdir(os.path.join(self.directory, 'oj')):
            os.mkdir(os.path.join(self.directory, 'oj'))
        self.Experiments = self.confargv['Experiments']

    def get_one_experiment_result(self, Experiment:dict):
        ExperimentResult = {}
        Inputs, Outputs = [], []

        for Input in Experiment['Inputs']:
            Output = subprocess.check_output(os.path.join(self.directory, Experiment['Path-to-EXE']), input=Input.encode()).decode()
            Output = Output.replace('\r\n', '\n')
            if Output[-1] == '\n':
                Output = Output[:-1]
            Inputs.append(Input)
            Outputs.append(Output)
        ExperimentResult['Input'] = Inputs
        ExperimentResult['Output'] = Outputs

        logger.info(f'{Experiment["Name"]} done.')
        return ExperimentResult
    
    def generate_test_points(self):
        for Experiment in self.Experiments['compulsive']:
            ExperimentResult = self.get_one_experiment_result(Experiment)
            if not os.path.isdir(os.path.join(self.directory, 'oj', Experiment['Name'])):
                os.mkdir(os.path.join(self.directory, 'oj', Experiment['Name']))
            for idx in range(len(ExperimentResult['Input'])):
                with open(os.path.join(self.directory, 'oj', Experiment['Name'], str(idx+1)+'.in'), 'w', encoding='utf-8') as f:
                    f.write(ExperimentResult['Input'][idx])
                with open(os.path.join(self.directory, 'oj', Experiment['Name'], str(idx+1)+'.out'), 'w', encoding='utf-8') as f:
                    f.write(ExperimentResult['Output'][idx])
             
        for Experiment in self.Experiments['optional']:
            ExperimentResult = self.get_one_experiment_result(Experiment)
            if not os.path.isdir(os.path.join(self.directory, 'oj', Experiment['Name'])):
                os.mkdir(os.path.join(self.directory, 'oj', Experiment['Name']))
            for idx in range(len(ExperimentResult['Input'])):
                with open(os.path.join(self.directory, 'oj', Experiment['Name'], str(idx+1)+'.in'), 'w', encoding='utf-8') as f:
                    f.write(ExperimentResult['Input'][idx])
                with open(os.path.join(self.directory, 'oj', Experiment['Name'], str(idx+1)+'.out'), 'w', encoding='utf-8') as f:
                    f.write(ExperimentResult['Output'][idx])

if __name__ == '__main__':
    if len(argv) == 1:
        myOjGenerator = OjGenerator('.')
    elif len(argv) == 2:
        myOjGenerator = OjGenerator(argv[1])
    else:
        logger.error('Too many arguments.')
        exit(1)
    myOjGenerator.generate_test_points()
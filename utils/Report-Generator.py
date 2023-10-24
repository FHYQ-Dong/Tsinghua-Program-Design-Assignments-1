from sys import argv
from loguru import logger
import subprocess
import os.path
import json

class MarkdownCreater:
    def __init__(self, path) -> None:
        self.path = path
        if os.path.isfile(self.path):
            logger.warning(f'File {self.path} already exists, overwrite it? [y/n]')
            if input() != 'y':
                logger.info('Abort.')
                exit(0)
            else:
                logger.info('Overwrite.')

    def create_markdown(self):
        self.markdown = open(self.path, 'w', encoding='utf-8')
    def close_markdown(self):
        self.markdown.close()

    def markdown_write_title(self, title):
        self.markdown.write(f'# {title}\n')
    def markdown_write_subtitle(self, subtitle):
        self.markdown.write(f'## {subtitle}\n')
    def markdown_write_subsubtitle(self, subsubtitle):
        self.markdown.write(f'### {subsubtitle}\n')

    def markdown_write_link(self, link, text):
        self.markdown.write(f'[{text}]({link})')
    def markdown_write_code(self, code, code_lang):
        self.markdown.write(f'```{code_lang}\n{code}\n```\n')
    def markdown_write_program(self, program, program_lang):
        self.markdown.write(f'代码: \n')
        self.markdown_write_code(program, program_lang)
    def markdown_write_input(self, input, input_id):
        self.markdown.write(f'输入{input_id}: \n```txt\n{input}\n```\n')
    def markdown_write_output(self, output, output_id):
        self.markdown.write(f'输出{output_id}: \n```txt\n{output}\n```\n')
    def markdown_write_newline(self):
        self.markdown.write('\n')

class ProjectReportCreater():
    def __init__(self, directory) -> None:
        self.directory = directory
        try:
            self.configFile = open(os.path.join(directory, 'Project.conf'), 'r', encoding='utf-8')
            self.confargv = json.load(self.configFile)
            self.configFile.close()
        except:
            logger.error('Project.conf not found.')
            exit(1)

        self.Name = self.confargv['Name']
        self.Url = self.confargv['Url']
        self.Environment = self.confargv['Environment']
        self.Experiments = self.confargv['Experiments']

        self.mdCreater = MarkdownCreater(os.path.join(directory, self.Name+'.md'))
        self.mdCreater.create_markdown()

    def get_one_experiment_result(self, Experiment:dict):
        ExperimentResult = {}
        with open(os.path.join(self.directory, Experiment['Path-to-C']), 'r', encoding='utf-8') as f:
            code = f.read()
            ExperimentResult['Code'] = code
        Inputs, Outputs = Experiment['Inputs'], []
        for Input in Inputs:
            Output = subprocess.check_output(os.path.join(self.directory, Experiment['Path-to-EXE']), input=Input.encode()).decode()
            Output = Output.replace('\r\n', '\n')
            if Output[-1] == '\n':
                Output = Output[:-1]
            Outputs.append(Output)

        ExperimentResult['Input'] = Inputs
        ExperimentResult['Output'] = Outputs
        logger.info(f'{Experiment["Name"]} done.')
        return ExperimentResult
    
    def write_report(self):
        self.mdCreater.markdown_write_title(self.Name)
        self.mdCreater.markdown.write('环境: \n')
        self.mdCreater.markdown_write_code('\n'.join(self.Environment), 'txt')
        self.mdCreater.markdown.write('作业仓库地址: \n')
        self.mdCreater.markdown_write_link(self.Url, self.Url)
        self.mdCreater.markdown_write_newline()
        self.mdCreater.markdown_write_subtitle('必做题')
        for Experiment in self.Experiments['compulsive']:
            self.mdCreater.markdown_write_subsubtitle(Experiment['Name'])
            ExperimentResult = self.get_one_experiment_result(Experiment)
            self.mdCreater.markdown_write_program(ExperimentResult['Code'], 'c')
            for idx in range(len(ExperimentResult['Input'])):
                self.mdCreater.markdown_write_input(ExperimentResult['Input'][idx], idx+1)
                self.mdCreater.markdown_write_output(ExperimentResult['Output'][idx], idx+1)
            self.mdCreater.markdown_write_newline()
        if 'optional' in self.Experiments:
            if len(self.Experiments['optional']) > 0:
                self.mdCreater.markdown_write_subtitle('选做题')
                for Experiment in self.Experiments['optional']:
                    self.mdCreater.markdown_write_subsubtitle(Experiment['Name'])
                    ExperimentResult = self.get_one_experiment_result(Experiment)
                    self.mdCreater.markdown_write_program(ExperimentResult['Code'], 'c')
                    for idx in range(len(ExperimentResult['Input'])):
                        self.mdCreater.markdown_write_input(ExperimentResult['Input'][idx], idx+1)
                        self.mdCreater.markdown_write_output(ExperimentResult['Output'][idx], idx+1)
                    self.mdCreater.markdown_write_newline()
        self.close_report()

    def close_report(self):
        logger.info('Report generated.')
        self.mdCreater.close_markdown()

if __name__ == '__main__':
    if len(argv) == 1:
        myReportCreater = ProjectReportCreater('.')
    elif len(argv) == 2:
        myReportCreater = ProjectReportCreater(argv[1])
    else:
        logger.error('Too many arguments.')
        exit(1)
    myReportCreater.write_report()
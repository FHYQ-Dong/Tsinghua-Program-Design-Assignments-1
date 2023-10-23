# Report-Generator 使用方法

**本工具适用于拥有部分 `python` 基础的同学**

**环境要求：python>=3.9 （3.9以下未测试）**

## 使用步骤

1. 安装第三方库：

   ```sh
   pip install -r python-sitepackage-requirements.txt
   ```

2. 在每周作业的根文件夹下创建 `Project.conf` 文件，用于生成的配置：

   详细文件内容可参见 [我的Project.conf](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments/blob/main/Experiment4/Project.conf)

3. 运行 `Report-Generator.py`:

   ```sh
   python Report-Generator.py .
   ```

   其中最后的 `.` 替换为你的 `Project.conf` 文件所在目录。

4. 程序会在 `Project.conf` 所在目录下生成一个 `markdown` 文件，可以用 `Typora` 等应用转为 `pdf`。
## Project.conf 参数解释

1. `Name`：报告名称；

2. `Url`：作业仓库地址，如 `github` 等（若未上传代码托管网站则需要删除，同时删除 `Report-Generator.py` 中第 `81-82` 行）；

3. `Environment`：编译环境；

4. `Experiments`：作业：

   1. `compulsive`：必做题：
      1. `Name`：该题名称；
      2. `Path`：相对于本周作业根文件夹的相对路径；
      3. `Inputs`：标准输入，由于可能需要多组输入，故用列表传入（可参见[我的第三次作业选做题](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments/blob/main/Experiment3/Experiment3-董皓彧.md#选做题)）

   2. `optional`：选做题，参数与必做题相同 
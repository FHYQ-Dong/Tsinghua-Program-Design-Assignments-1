files = [f'{i}.out' for i in range(1, 11)]
for file in files:
    content = ''
    with open(file, 'r') as f:
        content = f.read()
    content = content.replace('f(x) = ','').replace('f(x, y) = ','')
    if content[-1] == '\n':
        content = content[:-1]
    with open(file, 'w') as f:
        f.write(content)
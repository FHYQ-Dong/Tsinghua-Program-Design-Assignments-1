files = [f'{i}.out' for i in range(1, 11)]
for file in files:
    with open(file, 'r') as f:
        content = f.read()
    content = content.replace('length: ', '').replace('digits: ', '').replace('reverse: ', '')
    with open(file, 'w') as f:
        f.write(content)
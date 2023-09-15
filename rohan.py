with open('example.csv', 'r') as f:
    
    data = f.read().strip().split('\n')
    data = [numbers.split(',') for numbers in data]

for numbers in data:
    numbers.append(str(sum([int(n) for n in numbers])))

with open('sum_data.csv', 'w') as f:
    
    for numbers in data:
        f.write(','.join(numbers) + '\n')()
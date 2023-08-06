file_path = 'sum_data.csv'
new_data = [['4', '5'], ['2', '3']]

def read_csv_file(file_path):
    data = []
    with open(file_path, 'r') as f:
        for line in f:
            fields = line.strip().split(',')
            data.append(fields)
    return data


def write_to_csv_file(file_path, data):
    with open(file_path, 'w') as f:
        for row in data:
            sum_of_numbers = int(row[0]) + int(row[1])
            row.append(str(sum_of_numbers))
            line = ','.join(row) + '\n'
            f.write(line)

write_to_csv_file(file_path, new_data)
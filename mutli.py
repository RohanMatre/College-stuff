def mul(a, b):
    # result = [
    #     [0, 0, 0],
    #     [0, 0, 0],
    #     [0, 0, 0]]

    rows_a = len(a)
    cols_a = len(a[0])
    rows_b = len(b)
    cols_b = len(b[0])

    result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    for i in range(rows_a):
        for j in range(cols_a):
            for k in range(cols_b):
                result[i][j] += a[i][k] * b[k][j]
    return result

matrix1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]]

matrix2 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]]

result_matrix = mul(matrix1, matrix2)

for row in result_matrix:
    print(row)

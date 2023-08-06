def mul(a, b):
    rows_a = len(a)
    cols_a = len(a[0])
    rows_b = len(b)
    cols_b = len(b[0])

    if cols_a != rows_b:
        raise ValueError("The number of columns in the first matrix must be equal to the number of rows in the second matrix.")

    result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]
    return result

def determinant(matrix):
    n = len(matrix)
    if n == 1:
        return matrix[0][0]
    if n == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

    det = 0
    for c in range(n):
        submatrix = [row[:c] + row[c+1:] for row in matrix[1:]]
        sign = (-1) ** c
        det += sign * matrix[0][c] * determinant(submatrix)
    return det

def inverse(matrix):
    det = determinant(matrix)
    if det == 0:
        raise ValueError("The matrix is singular and does not have an inverse.")

    n = len(matrix)
    adjugate = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            submatrix = [row[:j] + row[j+1:] for row in (matrix[:i] + matrix[i+1:])]
            sign = (-1) ** (i+j)
            adjugate[j][i] = sign * determinant(submatrix)

    inverse_matrix = [[adjugate[i][j] / det for j in range(n)] for i in range(n)]

    return inverse_matrix

# Example usage:
matrix1 = [
    [1, 2, 3],
    [3, 2, 1],
    [3, 1, 2]]

result_matrix = mul(matrix1, inverse(matrix1))

for row in result_matrix:
    print(row)

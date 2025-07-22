#8.3.ж
import numpy as np

A = np.array([
    [2, 1, 3, -2, 1],
    [6, 3, 5, -4, 3],
    [2, 1, 7, -4, 1],
    [4, 2, 2, -3, 3]
])
b = np.array([4, 5, 11, 6])

x, residuals, rank, singular_values = np.linalg.lstsq(A, b, rcond=None)

print("Решение системы:", x)
print("Ранг матрицы A:", np.linalg.matrix_rank(A))

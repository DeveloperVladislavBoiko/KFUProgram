#17.2.б
import numpy as np

A = np.array([
    [3, 0, 2],
    [0, 1, 3],
    [2, 2, 0],
    [0, 1, 0]
])

B = np.array([
    [1, 2, -1, 2],
    [-2, -1, 1, 2],
    [2, 1, 1, 2]
])

C = np.array([
    [0, -4, 6, 1],
    [2, 2, -5, -2],
    [2, -2, 6, 4],
    [1, 3, 0, 1]
])

result = (A @ B)[:3, :] + C[:3, :]
print("Результат:")
print(result)

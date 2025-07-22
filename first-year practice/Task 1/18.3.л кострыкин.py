#18.3.л
import numpy as np

A = np.array([
    [2, 1, 0],
    [1, 2, 0],
    [0, 0, 1]
])

B = np.array([
    [0, 0, 1],
    [0, 1, 0],
    [1, 0, 0]
])

C = np.array([
    [0, 1, 0],
    [1, 0, 0],
    [0, 0, 0]
])

A_inv = np.linalg.inv(A)
B_inv = np.linalg.inv(B)

X = A_inv @ C @ B_inv
print("Решение X:")
print(X)

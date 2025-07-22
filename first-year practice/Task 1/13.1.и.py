#13.1.и
import numpy as np

matrix = np.array([
    [1, 1, 1, 1],
    [1, 2, 4, 8],
    [1, 3, 9, 27],
    [1, 4, 16, 64]
])

det = np.linalg.det(matrix)
print("Определитель:", det)

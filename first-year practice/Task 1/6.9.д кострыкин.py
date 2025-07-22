#6.9.д
import numpy as np
from sympy import symbols, Matrix, solve

lambda_ = symbols('lambda')

a1 = [3, 2, 6]
a2 = [5, 1, 3]
a3 = [7, 3, 9]
b = [lambda_, 2, 5]

A = Matrix([a1, a2, a3]).T
b_col = Matrix(b)

augmented = A.row_join(b_col)
rank_A = A.rank()
rank_augmented = augmented.rank()

if rank_A == rank_augmented:
    if rank_A == 3:
        solution = A.solve(b_col)
        print(f"λ может быть любым вещественным числом. Решение: {solution}")
    else:
        print("Система имеет бесконечно много решений. λ может быть любым вещественным числом.")
else:
    print("Нет таких λ.")

#3024
import sympy as sp

x, n = sp.symbols('x n')
series = sp.Sum(sp.cos((2*n - 1)*x) / (2*n - 1)**2, (n, 1, sp.oo)).doit()
print(series)

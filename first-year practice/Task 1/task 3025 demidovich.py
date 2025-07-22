#3025
import sympy as sp

x, n = sp.symbols('x n')
series = sp.Sum((-1)**(n-1) * sp.sin(n*x) / (n*(n+1)), (n, 1, sp.oo)).doit()
print(series)

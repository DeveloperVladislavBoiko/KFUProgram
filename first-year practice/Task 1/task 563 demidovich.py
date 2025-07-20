#563
import sympy as sp


x = sp.symbols('x')
expr = (1 - x) * sp.log(2, 2)
limit_expr = sp.limit(expr, x, 1)
print("Предел 563:", limit_expr)

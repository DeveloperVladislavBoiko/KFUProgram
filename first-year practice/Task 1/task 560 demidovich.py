#560
import sympy as sp

x, a = sp.symbols('x a')
expr = (a**x - a**(x**a)) / (a**x - x**a)
limit_expr = sp.limit(expr, x, a)
print("Предел 560:", limit_expr.simplify())

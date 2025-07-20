#562
import sympy as sp

x = sp.symbols('x')
expr = sp.ln(1 + 2**x) * sp.ln(1 + 3/x)
limit_expr = sp.limit(expr, x, sp.oo)
print("Предел 562:", limit_expr)

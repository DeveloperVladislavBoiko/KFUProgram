#561
import sympy as sp

x = sp.symbols('x')
expr_a = sp.ln(1 + 3**x) / sp.ln(1 + 2**x)
limit_a = sp.limit(expr_a, x, -sp.oo)
print("Предел 561a:", limit_a)

expr_b = sp.ln(1 + 3**x) / sp.ln(1 + 2**x)
limit_b = sp.limit(expr_b, x, sp.oo)
print("Предел 561b:", limit_b)

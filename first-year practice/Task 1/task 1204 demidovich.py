#1204
from sympy import symbols, exp, apart

x = symbols('x')
y = (x**2 + 2*x + 2) * exp(-x)
try:
    decomposition = apart(y, x)
    print("Разложение на простейшие дроби:")
    print(decomposition)
except:
    print("Функция не является рациональной дробью. Разложение невозможно.")
    print("Исходная функция:", y)

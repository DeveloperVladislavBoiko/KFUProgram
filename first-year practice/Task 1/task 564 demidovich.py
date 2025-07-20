#564
"""
в данном номере необходимо доказать что предел равен нулю, это возможно осуществить благодаря графику,
который для любых переменных удовлетворющих условиям равен нулю.
"""
import numpy as np
import matplotlib.pyplot as plt



def plot_and_save_limit_564():
    x_vals = np.linspace(1, 20, 100)
    a_values = [2, 3]
    n_values = [1, 2, 3]
    plt.figure(figsize=(10, 6))

    for a in a_values:
        for n in n_values:
            y_vals = (x_vals ** n) / (a ** x_vals)
            plt.plot(x_vals, y_vals, label=f'a={a}, n={n}')

    plt.title('График функции $f(x) = \\frac{x^n}{a^x}$')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.yscale('log')
    plt.grid(True)
    plt.legend()
    plt.savefig('564.png', dpi=300, bbox_inches='tight')
    plt.close()

    return '564.png'


# Построение и сохранение графика
plot_filename = plot_and_save_limit_564()
print(f"\nГрафик для задачи 564 сохранён в файл: {plot_filename}")

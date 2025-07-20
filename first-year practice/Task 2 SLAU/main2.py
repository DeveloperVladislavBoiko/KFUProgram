def gauss_SLAU():
    n = int(input("Введите количество уравнений: "))
    m = int(input("Введите количество переменных: "))
    print("Введите коэффициенты системы (построчно, разделяя пробелами):")

    matrix = []
    for i in range(n):
        row = list(map(float, input().split()))
        if len(row) != m + 1:
            print("Ошибка: количество элементов в строке не соответствует размерности системы")
            return None
        matrix.append(row)

    print("\nДоступные переменные: ", ", ".join(f"x{i + 1}" for i in range(m)))
    print("Введите номера переменных, которые должны быть базисными (через пробел, нумерация с 1):")
    pivot_choice_input = input().strip()

    if not pivot_choice_input:
        pivot_choice = []
    else:
        pivot_choice = list(map(int, pivot_choice_input.split()))
        pivot_choice = [x - 1 for x in pivot_choice if 1 <= x <= m]  # Фильтруем некорректные значения

    rank = 0
    n_vars = m
    pivot_cols = []

    for col in pivot_choice:
        if col >= n_vars or col in pivot_cols:
            continue

        max_row = rank
        for i in range(rank, n):
            if i < len(matrix) and col < len(matrix[i]) and abs(matrix[i][col]) > abs(matrix[max_row][col]):
                max_row = i

        if max_row >= n or col >= len(matrix[max_row]) or abs(matrix[max_row][col]) < 1e-10:
            print(
                f"Предупреждение: выбранная переменная x{col + 1} не может быть базисной (нулевой столбец или выход за границы)")
            continue

        matrix[rank], matrix[max_row] = matrix[max_row], matrix[rank]

        pivot = matrix[rank][col]
        for j in range(col, n_vars + 1):
            if j < len(matrix[rank]):  
                matrix[rank][j] /= pivot

        for i in range(n):
            if i != rank and i < len(matrix) and col < len(matrix[i]) and abs(matrix[i][col]) > 1e-10:
                factor = matrix[i][col]
                for j in range(col, n_vars + 1):
                    if j < len(matrix[i]):  
                        matrix[i][j] -= factor * matrix[rank][j]

        pivot_cols.append(col)
        rank += 1

    for col in range(n_vars):
        if col in pivot_cols:
            continue

        max_row = rank
        for i in range(rank, n):
            if i < len(matrix) and col < len(matrix[i]) and abs(matrix[i][col]) > abs(matrix[max_row][col]):
                max_row = i

        if max_row >= n or col >= len(matrix[max_row]) or abs(matrix[max_row][col]) < 1e-10:
            continue

        matrix[rank], matrix[max_row] = matrix[max_row], matrix[rank]

        pivot = matrix[rank][col]
        for j in range(col, n_vars + 1):
            if j < len(matrix[rank]):
                matrix[rank][j] /= pivot

        for i in range(n):
            if i != rank and i < len(matrix) and col < len(matrix[i]) and abs(matrix[i][col]) > 1e-10:
                factor = matrix[i][col]
                for j in range(col, n_vars + 1):
                    if j < len(matrix[i]):
                        matrix[i][j] -= factor * matrix[rank][j]

        pivot_cols.append(col)
        rank += 1

    for i in range(rank, n):
        if i < len(matrix) and n_vars < len(matrix[i]) and abs(matrix[i][n_vars]) > 1e-10:
            print("\nСистема не имеет решений (несовместна).")
            return None

    if rank < n_vars:
        print("\nСистема имеет бесконечно много решений.")
        free_vars = n_vars - rank
        print(f"Количество свободных переменных: {free_vars}")

        basis = pivot_cols
        free = [col for col in range(n_vars) if col not in basis]

        not_in_basis = [x for x in pivot_choice if x not in basis]
        for col in not_in_basis:
            print(f"Предупреждение: выбранная переменная x{col + 1} не вошла в базис")

        print("\nОбщее решение (базисные переменные выражены через свободные):")
        for i in range(rank):
            if i < len(matrix):
                col = basis[i] if i < len(basis) else -1
                if col == -1:
                    continue
                expr = []
                for j in free:
                    if j < len(matrix[i]):
                        coeff = -matrix[i][j] if j != col else 0.0
                        if abs(coeff) > 1e-10:
                            expr.append(f"{coeff:.2f}*x{j + 1}")
                const = matrix[i][n_vars] if n_vars < len(matrix[i]) else 0.0
                if abs(const) > 1e-10 or not expr:
                    expr.append(f"{const:.2f}")
                print(f"x{col + 1} = " + " + ".join(expr))

        print("\nСвободные переменные:")
        for j in free:
            print(f"x{j + 1} = свободный параметр")

        return None
    else:
        solution = [matrix[i][n_vars] for i in range(n_vars) if i < len(matrix) and n_vars < len(matrix[i])]
        print("\nРешение системы:")
        for i, x in enumerate(solution, 1):
            print(f"x{i} = {x:.6f}")
        return solution


gauss_SLAU()

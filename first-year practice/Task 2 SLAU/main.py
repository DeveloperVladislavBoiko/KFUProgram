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

    rank = 0
    n_vars = m
    pivot_cols = []

    for col in range(n_vars):
        max_row = rank
        for i in range(rank, n):
            if abs(matrix[i][col]) > abs(matrix[max_row][col]):
                max_row = i

        if abs(matrix[max_row][col]) < 1e-10:
            continue

        matrix[rank], matrix[max_row] = matrix[max_row], matrix[rank]

        pivot = matrix[rank][col]
        for j in range(col, n_vars + 1):
            matrix[rank][j] /= pivot

        for i in range(n):
            if i != rank and abs(matrix[i][col]) > 1e-10:
                factor = matrix[i][col]
                for j in range(col, n_vars + 1):
                    matrix[i][j] -= factor * matrix[rank][j]

        pivot_cols.append(col)
        rank += 1

    for i in range(rank, n):
        if abs(matrix[i][n_vars]) > 1e-10:
            print("\nСистема не имеет решений (несовместна).")
            return None

    if rank < n_vars:
        print("\nСистема имеет бесконечно много решений.")
        free_vars = n_vars - rank
        print(f"Количество свободных переменных: {free_vars}")

        basis = pivot_cols
        free = [col for col in range(n_vars) if col not in basis]

        print("\nОбщее решение (базисные переменные выражены через свободные):")
        for i in range(rank):
            col = basis[i]
            expr = []
            for j in free:
                coeff = -matrix[i][j] if j != col else 0.0
                if abs(coeff) > 1e-10:
                    expr.append(f"{coeff:.2f}*x{j + 1}")
            const = matrix[i][n_vars]
            if abs(const) > 1e-10 or not expr:
                expr.append(f"{const:.2f}")
            print(f"x{col + 1} = " + " + ".join(expr))

        print("\nСвободные переменные:")
        for j in free:
            print(f"x{j + 1} = свободный параметр")

        return None
    else:
        solution = [matrix[i][n_vars] for i in range(n_vars)]
        print("\nРешение системы:")
        for i, x in enumerate(solution, 1):
            print(f"x{i} = {x:.6f}")
        return solution

gauss_SLAU()

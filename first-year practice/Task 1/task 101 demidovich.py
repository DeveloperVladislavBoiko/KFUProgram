def numerical_sequence_101(n_max=10**6):
    x_large = 1 - 1 / n_max
    inf_xn = 0  # достигается при n=1
    sup_xn = x_large  # стремится к 1
    limit = x_large  # предел равен 1
    limsup = limit
    return inf_xn, sup_xn, limit, limsup

inf, sup, limit, limsup = numerical_sequence_101()
print(f"inf x_n = {inf}, sup x_n ≈ {sup:.6f}, lim x_n ≈ {limit:.6f}, limsup x_n ≈ {limsup:.6f}")

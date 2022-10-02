# c |= base^exp % m

def modpow(base, exp, m):
    result = 1

    while exp > 0:
        if (exp & 1) > 0:
            result = (result * base) % m
        exp >>= 1
        base = (base * base) % m

    return result


print(modpow(3, 3, 5))

import sys
import math


def get_prime_factors(n):
    result = []

    r = 0
    while n % 2 == 0:
        r += 1
        n /= 2

    if r:
        result.append((2, r))

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        r = 0
        while (n % i == 0):
            r += 1
            n /= i
        if r:
            result.append((i, r))

    if n > 2:
        result.append((n, 1))

    return result


while True:
    n = int(sys.stdin.readline())
    if not n:
        break

    primes = get_prime_factors(n)
    i = 1
    for p in primes:
        i *= p[1] + 1
    if i % 2:
        print("yes")
    else:
        print("no")

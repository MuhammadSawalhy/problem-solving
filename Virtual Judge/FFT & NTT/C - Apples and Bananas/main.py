import sys
import cmath


def fft(x):
    n = len(x)
    if n <= 1:
        return x
    even = fft(x[0::2])
    odd = fft(x[1::2])
    T = [cmath.exp(-2j * cmath.pi * k / n) * odd[k] for k in range(n // 2)]
    return [even[k] + T[k] for k in range(n // 2)] + [
        even[k] - T[k] for k in range(n // 2)
    ]


def ifft(x):
    n = len(x)
    x_conj = [val.conjugate() for val in x]
    fft_x_conj = fft(x_conj)
    return [val.conjugate() / n for val in fft_x_conj]


def solve():
    input = sys.stdin.read().split()
    ptr = 0
    k, n, m = map(int, input[ptr : ptr + 3])
    ptr += 3

    a = list(map(int, input[ptr : ptr + n]))
    ptr += n
    b = list(map(int, input[ptr : ptr + m]))

    max_size = 1
    while max_size < 2 * k + 1:
        max_size <<= 1

    countA = [0] * max_size
    for num in a:
        if num <= k:
            countA[num] += 1

    countB = [0] * max_size
    for num in b:
        if num <= k:
            countB[num] += 1

    fft_A = fft(countA)
    fft_B = fft(countB)

    fft_product = [a * b for a, b in zip(fft_A, fft_B)]

    product = ifft(fft_product)
    product = [int(round(val.real)) for val in product]

    output = []
    for w in range(2, 2 * k + 1):
        if w < len(product):
            output.append(str(product[w]))
        else:
            output.append("0")
    print(" ".join(output))


solve()

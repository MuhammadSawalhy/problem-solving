from decimal import Decimal, getcontext


def expected_inversions(n: int, r):
    # Set the precision high enough to handle calculations
    getcontext().prec = 100  # Adjust precision as needed

    total = Decimal(0.0)
    for a in range(n):
        for b in range(a + 1, n):
            r_a, r_b = r[a], r[b]
            cnt = 0
            for i in range(1, r_b + 1):
                cnt += max(r_a - i, 0)
            # Normalize by r_a * r_b
            p = Decimal(cnt) / (r_a * r_b)
            total += p
    return total


# Read input
n = int(input())
r = list(map(int, input().split()))

# Compute expected inversions
result = expected_inversions(n, r)

# Round to six decimal places (round half to even)
rounded_result = round(result, 6)

# Print the result with six decimal places
print(f"{float(rounded_result):.6f}")

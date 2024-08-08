# Read input
Y = int(input())

# Determine the number of days in the year Y
if Y % 4 != 0:
    days = 365
elif Y % 100 != 0:
    days = 366
elif Y % 400 != 0:
    days = 365
else:
    days = 366

# Output the result
print(days)


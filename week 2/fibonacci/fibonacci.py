# Uses python3
import random

def fibonacci_naive(n):
    if (n <= 1):
        return n

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2)

def fibonacci_fast(n):
    if (n <= 1):
        return n

    a = 0
    b = 1
    c = 1
    i = 2

    while i <= n:
        c = a + b
        a = b
        b = c
        i += 1

    return c

count = int(input('Run tests for: '))

while count > 0:
    n = random.randint(0, 45)
    if fibonacci_fast(n) != fibonacci_naive(n):
        print('Test Failed')
        sys.exit(0)

    print 'Test passed for ' + str(n)
    count -= 1

print 'All Good'

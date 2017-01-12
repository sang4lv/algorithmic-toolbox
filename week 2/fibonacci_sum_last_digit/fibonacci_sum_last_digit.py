# Uses python3
import sys
import random

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def fibonacci_sum_fast(n):
    if n <= 1:
        return n

    previous = 0
    current = 1
    total = 1

    for _ in range(n - 1):
        previous, current = current, (previous + current) % 10
        total = (total + current) % 10

    return total

if __name__ == '__main__':
    count = int(input('Run tests for: '))

    while count > 0:
        n = random.randint(0, 10**14)
        if fibonacci_sum_naive(n) != fibonacci_sum_fast(n):
            print('Test Failed')
            sys.exit(0)

        print 'Test passed for ' + str(n)
        count -= 1

    print 'All Good'

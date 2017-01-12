# Uses python3
import sys
import random

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10

def get_fibonacci_last_digit_fast(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, (previous + current) % 10

    return current

if __name__ == '__main__':
    count = int(input('Run tests for: '))

    while count > 0:
        n = random.randint(0, 10**7)
        if get_fibonacci_last_digit_naive(n) != get_fibonacci_last_digit_fast(n):
            print('Test Failed')
            sys.exit(0)

        print 'Test passed for ' + str(n)
        count -= 1

    print 'All Good'

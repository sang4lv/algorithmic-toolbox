# Uses python3
import sys

def fibonacci_partial_sum_naive(from_, to):
    if to <= 1:
        return to

    previous = 0
    current  = 1

    for _ in range(from_ - 1):
        previous, current = current, previous + current

    sum = current

    for _ in range(to - from_):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def fibonacci_partial_sum_fast(from_, to):
    if to <= 1:
        return to

    previous = 0
    current = 1
    total = 0

    for i in range(2, to + 1, 1):
        previous, current = current, (previous + current) % 10
        if i >= from_:
            total = (total + current) % 10

    return total

if __name__ == '__main__':
    passed = True

    while passed:
        from_, to = map(int, sys.stdin.readline().split())
        print(fibonacci_partial_sum_fast(from_, to) == fibonacci_partial_sum_naive(from_, to))

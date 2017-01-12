# Uses python3
import sys
import random

def gcd_fast(a, b):
    if a == 0:
        return b
    if b == 0:
        return a

    return gcd_fast(b, a % b)

def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l

    return a*b

def lcm_fast(a, b):
    gcd = gcd_fast(a, b)

    return a / gcd * b

def test_solution(n):
    for _ in range(n):
        a = random.randint(0, 10**4)
        b = random.randint(0, 10**4)
        if lcm_fast(a, b) != lcm_naive(a, b):
            print('Test failed for ' + str(a) + ' ' + str(b))
            sys.exit(0)

if __name__ == '__main__':
    test_solution(int(sys.stdin.readline()))

    # passed = True
    #
    # while passed:
    #     a, b = map(int, sys.stdin.readline().split())
    #     passed = (lcm_naive(a, b) == lcm_fast(a, b))
    #     print('Test passed: ' + str(passed))

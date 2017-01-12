# Uses python3
import sys

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def gcd_fast(a, b):
    if a == 0:
        return b
    if b == 0:
        return a

    return gcd_fast(b, a % b)

if __name__ == '__main__':
    passed = True

    while passed:
        a, b = map(int, sys.stdin.readline().split())
        passed = (gcd_naive(a, b) == gcd_fast(a, b))
        print('Test passed: ' + str(passed))

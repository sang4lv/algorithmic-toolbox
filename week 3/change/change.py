# Uses python3
import sys
import math

def get_change(m):
    denom = [1, 5, 10]
    index = len(denom) - 1
    total = 0

    while m > 0:
        if m >= denom[index]:
            total += math.floor(m / denom[index])
            m %= denom[index]
        else:
            index -= 1

    return total

def test_solution():
    assert get_change(0) == 0
    assert get_change(10) == 1
    assert get_change(9) == 5
    assert get_change(2) == 2
    assert get_change(28) == 6

if __name__ == '__main__':
    test_solution()

    while True:
        print get_change(int(sys.stdin.readline()))

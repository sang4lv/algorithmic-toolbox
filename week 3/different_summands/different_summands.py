# Uses python3
import sys

def optimal_summands(n):
    if n <= 2:
        return [n]

    l = 1
    summands = []

    while n > 2 * l:
        summands.append(l)
        n -= l
        l += 1

    if n > 0:
        summands.append(n)

    return summands

def test_solution():
    are_lists_identical(optimal_summands(2), [2])
    are_lists_identical(optimal_summands(5), [1, 4])
    are_lists_identical(optimal_summands(6), [1, 2, 3])
    are_lists_identical(optimal_summands(8), [1, 2, 5])

def are_lists_identical(l1, l2):
    assert len(set(l1).union(l2)) == len(l1)

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')

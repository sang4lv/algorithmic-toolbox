#Uses python3
import sys
import math

def selection_sort(a):
    for i in range(0, len(a) - 1):
        curr_index = i
        for j in range(i + 1, len(a)):
            if a[j] > a[curr_index]:
                curr_index = j

        a[i], a[curr_index] = a[curr_index], a[i]

    return a

def max_dot_product(a, b):
    assert len(a) == len(b)

    a = selection_sort(a)
    b = selection_sort(b)

    res = 0

    for i in range(len(a)):
        res += a[i] * b[i]

    return res

def test_solution():
    assert max_dot_product([23], [39]) == 897
    assert max_dot_product([1, 3, -5], [-2, 4, 1]) == 23
    assert max_dot_product([3, 2, 8], [-2, -3, -4]) == -33

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:(n + 1)]
    b = data[(n + 1):]
    print(max_dot_product(a, b))

#Uses python3

import sys

def largest_number(a):
    for i in range(len(a) - 1):
        swap = i
        for j in range(i + 1, len(a)):
            if a[swap] < a[j]:
                swap = j

        a[swap], a[i] = a[i], a[swap]

    return ''.join(map(str, a))

def test_solution():
    assert largest_number([3, 4, 2]) == '432'
    assert largest_number([38, 4, 79]) == '79384'

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))

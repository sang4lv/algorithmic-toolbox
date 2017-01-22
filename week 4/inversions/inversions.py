# Uses python3
import sys

def merge(a, b, inversions):
    i = 0
    j = 0
    res = []

    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            res.append(a[i])
            i += 1
        else:
            res.append(b[j])
            j += 1

    curr_inversions = j

    if i < len(a):
        if len(b):
            curr_inversions += (len(b) - i - 1)
        res += a[i:]

    if j < len(b):
        res += b[j:]

    return (res, inversions + curr_inversions)

def merge_sort(arr, i=0):
    length = len(arr)

    if length == 1:
        return (arr, 0)

    m = length // 2
    (half1, i1) = merge_sort(arr[:m], i)
    (half2, i2) = merge_sort(arr[m:], i)

    return merge(half1, half2, i1 + i2)

def get_number_of_inversions(a, b, left, right):
    (_, i) = merge_sort(a)
    return i

def test_solution():
    (_, i) = merge_sort([2, 3, 9, 2, 9])
    assert i == 2
    (_, i) = merge_sort([1, 2, 3, 4, 5])
    assert i == 0
    (_, i) = merge_sort([5, 4, 3, 2, 1])
    assert i == 10

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)))

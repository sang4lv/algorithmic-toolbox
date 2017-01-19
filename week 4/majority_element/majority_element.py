# Uses python3
import sys

def get_majority_element_on(a):
    map_by_count = {}

    for i in range(len(a)):
        if a[i] in map_by_count:
            map_by_count[a[i]] += 1
        else:
            map_by_count[a[i]] = 1

    threshold = len(a) // 2 + 1
    for (key, val) in map_by_count.items():
        if val >= threshold:
            return 1

    return 0

def get_majority_element(a, left, right):
    if left + 1 == right:
        return

    mid = (left + right) // 2
    get_majority_element(a, left, mid)
    get_majority_element(a, mid, right)

    first = a[left:mid]

    i = 0
    j = mid
    k = left

    while i + left < mid and j < right:
        if first[i] <= a[j]:
            a[k] = first[i]
            i += 1
        else:
            a[k] = a[j]
            j += 1
        k += 1

    while left + i < mid:
        a[k] = first[i]
        k += 1
        i += 1

    if left == 0 and right == len(a):
        if a[mid] == a[0] or a[mid - 1] == a[right - 1]:
            return 1
        else:
            return 0

def test_solution():
    assert get_majority_element_on([1, 2, 3, 4]) == 0
    assert get_majority_element_on([2, 2, 3, 4]) == 0
    assert get_majority_element_on([2, 3, 2, 3, 2, 2, 3, 2]) == 1
    assert get_majority_element([1, 2, 3, 4], 0, 4) == 0
    assert get_majority_element([2, 2, 3, 4], 0, 4) == 0
    assert get_majority_element([2, 2, 3, 3, 2, 2, 2, 3], 0, 8) == 1

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)

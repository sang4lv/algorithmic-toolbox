def insertion_sort(a):
    for i in range(1, len(a)):
        curr = a[i]
        index = i

        while index > 0 and curr < a[index - 1]:
            a[index] = a[index - 1]
            index -= 1

        a[index] = curr

    return a

def insertion_sort_recursion(a, i=1):
    if i == len(a):
        return a

    curr = a[i]
    index = i

    while index > 0 and curr < a[index - 1]:
        a[index] = a[index - 1]
        index -= 1

    a[index] = curr

    return insertion_sort_recursion(a, i + 1)


def test_solution():
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [5, 4, 3, 2, 1]
    arr3 = [6, 2, 5, 1, 5, 7]

    assert insertion_sort(arr1) == arr1
    assert insertion_sort_recursion(arr1) == arr1
    assert insertion_sort(arr2) == arr1
    assert insertion_sort_recursion(arr2) == arr1
    assert insertion_sort(arr3) == [1, 2, 5, 5, 6, 7]
    assert insertion_sort_recursion(arr3) == [1, 2, 5, 5, 6, 7]

if __name__ == '__main__':
    test_solution()

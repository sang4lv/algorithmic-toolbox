def selection_sort(a):
    for i in range(0, len(a) - 1):
        index = i
        for j in range(i + 1, len(a)):
            if a[j] < a[index]: # compare here
                index = j

        a[i], a[index] = a[index], a[i]

    return a

def selection_sort_recursion(a, i=0):
    if i == len(a):
        return a

    index = i
    for j in range(i + 1, len(a)):
        if a[j] < a[index]: # compare here
            index = j

    a[i], a[index] = a[index], a[i]

    return selection_sort_recursion(a, i + 1)

def test_solution():
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [5, 4, 3, 2, 1]
    arr3 = [6, 2, 5, 1, 5, 7]

    assert selection_sort(arr1) == arr1
    assert selection_sort_recursion(arr1) == arr1
    assert selection_sort(arr2) == arr1
    assert selection_sort_recursion(arr2) == arr1
    assert selection_sort(arr3) == [1, 2, 5, 5, 6, 7]
    assert selection_sort_recursion(arr3) == [1, 2, 5, 5, 6, 7]

if __name__ == '__main__':
    test_solution()

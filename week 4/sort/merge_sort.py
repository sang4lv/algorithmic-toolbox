def merge(a, b):
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

    if i < len(a):
        res += a[i:]

    if j < len(b):
        res += b[j:]

    return res

def merge_sort(arr):
    length = len(arr)

    if length == 1:
        return arr

    m = length // 2
    half1 = merge_sort(arr[:m])
    half2 = merge_sort(arr[m:])

    return merge(half1, half2)

def merge_sort_in_place(arr, left, right):
    if left + 1 == right:
        return

    mid = (left + right) // 2
    merge_sort_in_place(arr, left, mid)
    merge_sort_in_place(arr, mid, right)

    i = 0
    j = mid
    k = left

    first_half = arr[left:mid]

    while i + left < mid and j < right:
        if first_half[i] <= arr[j]:
            arr[k] = first_half[i]
            i += 1
        else:
            arr[k] = arr[j]
            j += 1
        k += 1

    while i + left < mid:
        arr[k] = first_half[i]
        i += 1
        k += 1

def test_solution():
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [5, 4, 3, 2, 1]
    arr3 = [6, 2, 5, 1, 5, 7]

    assert merge_sort(arr1) == arr1
    arr4 = arr1[:]
    merge_sort_in_place(arr4, 0, len(arr4))
    assert arr4 == arr1
    assert merge_sort(arr2) == arr1
    arr5 = arr2[:]
    merge_sort_in_place(arr5, 0, len(arr5))
    assert arr5 == arr1
    assert merge_sort(arr3) == [1, 2, 5, 5, 6, 7]
    arr6 = arr3[:]
    merge_sort_in_place(arr6, 0, len(arr6))
    assert arr6 == [1, 2, 5, 5, 6, 7]

if __name__ == '__main__':
    test_solution()

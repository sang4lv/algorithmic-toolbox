import random

def partition3(a, l, r):
    lower_bound = l
    upper_bound = l
    pivot = a[l]

    for i in range(l + 1, r + 1):
        if a[i] < pivot:
            lower_bound += 1
            upper_bound += 1
            a[i], a[lower_bound] = a[lower_bound], a[i]
        elif a[i] == pivot:
            upper_bound += 1
            a[i], a[upper_bound] = a[upper_bound], a[i]

    a[l], a[lower_bound] = a[lower_bound], a[l]
    return (lower_bound, upper_bound)

def partition2(a, l, r):
    x = a[l]
    j = l;
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            print '%s is smaller than %s' % (a[i], x)
            print 'swapping indices %s %s' % (i, j)
            j += 1
            a[i], a[j] = a[j], a[i]
        print a
    a[l], a[j] = a[j], a[l]
    print a
    return j

def randomized_quick_sort_p2(a, l, r):
    if l >= r:
        return

    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]

    m = partition2(a, l, r)
    randomized_quick_sort_p2(a, l, m - 1)
    randomized_quick_sort_p2(a, m + 1, r)

def randomized_quick_sort_p3(a, l, r):
    if l >= r:
        return

    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]

    (lower, upper) = partition3(a, l, r)
    randomized_quick_sort_p3(a, l, lower - 1)
    randomized_quick_sort_p3(a, upper + 1, r)

def test_solution():
    arr1 = [1, 2, 3, 4, 5]
    arr2 = [5, 4, 3, 2, 1]
    arr3 = [6, 2, 5, 1, 5, 7]

    assert randomized_quick_sort_p2(arr1) == arr1
    assert randomized_quick_sort_p3(arr1) == arr1
    assert randomized_quick_sort_p2(arr2) == arr1
    assert randomized_quick_sort_p3(arr2) == arr1
    assert randomized_quick_sort_p2(arr3) == [1, 2, 5, 5, 6, 7]
    assert randomized_quick_sort_p3(arr3) == [1, 2, 5, 5, 6, 7]

if __name__ == '__main__':
    test_solution()

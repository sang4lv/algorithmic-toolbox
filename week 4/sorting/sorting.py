# Uses python3
import sys
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

def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    # m = partition2(a, l, r)
    # randomized_quick_sort(a, l, m - 1);
    # randomized_quick_sort(a, m + 1, r);
    (lower, upper) = partition3(a, l, r)
    randomized_quick_sort(a, l, lower - 1)
    randomized_quick_sort(a, upper + 1, r)

def test_solution():
    arr = [5, 4, 3, 2, 1]
    randomized_quick_sort(arr, 0, len(arr) - 1)
    assert ''.join(map(str, arr)) == '12345'
    arr = [5, 1, 7, 3, 6, 5]
    randomized_quick_sort(arr, 0, len(arr) - 1)
    assert ''.join(map(str, arr)) == '135567'
    arr = [-1, -1, -1]
    randomized_quick_sort(arr, 0, len(arr) - 1)
    assert ''.join(map(str, arr)) == '-1-1-1'

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')

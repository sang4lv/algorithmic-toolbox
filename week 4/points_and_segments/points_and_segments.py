# Uses python3
import sys
import functools

def binary_search(a, x):
    left, right = 0, len(a) - 1

    while left <= right:
        mid = (left + right) / 2

        if a[mid] == x:
            return mid
        elif a[mid] < x:
            left = mid + 1
        elif a[mid] > x:
            right = mid - 1

    return -1

def get_count(a, x):
    pos = binary_search(a, x)

    if pos == -1:
        return 0

    count = 1
    lower = 0
    upper = len(a) - 1
    i = 1

    while lower <= a[pos + i] <= upper and a[pos + i] == x:
        i += 1
        count += 1
    i = -1
    while lower <= a[pos + i] <= upper and a[pos + i] == x:
        i -= 1
        count += 1

    return count

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

def fast_count_segments(starts, ends, points):
    all_ranges = []
    set_count = len(starts)

    for i in range(set_count):
        all_ranges.append(range(starts[i], ends[i] + 1))
    all_points = all_ranges[0]

    if set_count > 1:
        while set_count > 1:
            all_points = []

            for i in range(0, set_count, 2):
                if i + 1 < set_count:
                    all_points.append(merge(all_ranges[i], all_ranges[i + 1]))
                else:
                    all_points.append(all_ranges[i])

            all_ranges = all_points
            set_count = len(all_points)

        all_points = all_ranges[0]

    count = functools.partial(get_count, all_points)

    return map(count, points)

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

def test_solution():
    assert fast_count_segments([7, 0, 8], [10, 4, 13], [1, 6, 10]) == [1, 0, 2]
    assert fast_count_segments([0, -3, 7], [5, 2, 10], [1, 6]) == [2, 0]
    assert fast_count_segments([-10], [10], [-100, 100, 0]) == [0, 0, 1]

if __name__ == '__main__':
    test_solution()

    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = naive_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')

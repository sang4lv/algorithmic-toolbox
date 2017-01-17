# Uses python3
import sys

def binary_search(a, x):
    left, right = 0, len(a)

    while left <= right:
        mid = (left + right) / 2

        if a[mid] == x:
            return mid
        elif a[mid] < x:
            left = mid + 1
        elif a[mid] > x:
            right = mid - 1

    return -1

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i

    return -1

if __name__ == '__main__':
    user_input = sys.stdin.readline()

    while user_input != '\n':
        a = list(map(int, user_input.split()))
        lin_result = linear_search(a[1:], a[0])
        bin_result = binary_search(a[1:], a[0])
        if lin_result != bin_result:
            print 'bad implementation, is supposed to get %s, but instead got %s' % lin_result, bin_result

        user_input = sys.stdin.readline()

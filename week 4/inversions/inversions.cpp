#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;

  if (left + 1 >= right) {
    // b is empty at first, so we need to populate it with values of a
    for (size_t i = left; i < right; i++) {
      b[i] = a[i];
    }

    return number_of_inversions;
  }

  size_t mid = (left + right) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid, right);

  // save the first half
  size_t size = mid - left;
  std::vector<int> v{(int)size};
  for (size_t i = 0; i < size; i++) {
    v[i] = b[left + i];
  }

  // before recursion ends
  // elements in b needs to be in correct position
  size_t i = 0;
  size_t j = mid;
  size_t k = left;

  while (i < size && j < right) {
    if (v[i] <= b[j]) {
      b[k++] = v[i++];
    } else {
      b[k++] = b[j++];
      number_of_inversions++;
    }
  }

  while (i < size) {
    if (right - mid > 1) {
      number_of_inversions++;
    }
    b[k++] = v[i++];
  }

  return number_of_inversions;
}

void test_solution() {
  long long result;
  int size = 5;
  std::vector<int> a{size};
  std::vector<int> b{size};
  a = {2, 3, 9, 2, 9};
  result = get_number_of_inversions(a, b, 0, size);
  assert(result == 2);
  a = {1, 2, 3, 4, 5};
  result = get_number_of_inversions(a, b, 0, size);
  assert(result == 0);
  a = {5, 4, 3, 2, 1};
  result = get_number_of_inversions(a, b, 0, size);
  assert(result == 10);
}

int main() {
  test_solution();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}

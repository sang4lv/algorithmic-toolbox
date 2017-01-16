#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

void selection_sort(vector<int> &a) {
  size_t size = a.size();
  int max_index, temp;

  for (int i = 0; i < size - 1; i++) {
    max_index = i;
    for (int j = i + 1; j < size; j++) {
      if (a[j] > a[max_index]) {
        max_index = j;
      }
    }

    temp = a[i];
    a[i] = a[max_index];
    a[max_index] = temp;
  }
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // sort
  selection_sort(a);
  selection_sort(b);

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i] << ' ' << b[i] << '\n';
    result += ((long long) a[i]) * b[i];
  }

  std::cout << result << '\n';
  return result;
}

void test_solution() {
  assert(max_dot_product({23}, {39}) == 897);
  assert(max_dot_product({1, 3, -5}, {-2, 4, 1}) == 23);
  assert(max_dot_product({3, 2, 8}, {-2, -3, -4}) == -33);
}

int main() {
  test_solution();

  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

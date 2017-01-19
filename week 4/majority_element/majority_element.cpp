#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cout;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left + 1 == right) {
    return 0;
  }

  int mid = (left + right) / 2;
  get_majority_element(a, left, mid);
  get_majority_element(a, mid, right);

  std::vector<int> first{mid - left - 1};
  for (int b = left; b < mid; b++) {
    first[b - left] = a[b];
  }

  int i = 0, j = mid, k = left;
  while (i + left < mid && j < right) {
    if (first[i] <= a[j]) {
      a[k++] = first[i++];
    } else {
      a[k++] = a[j++];
    }
  }

  while (left + i < mid) {
    a[k++] = first[i++];
  }

  if (left == 0 && right == a.size()) {
    return (a[mid] == a[0] || a[mid - 1] == a[right - 1]);
  }

  return 0;
}

void test_solution() {
  std::vector<int> v;
  v = {1, 2, 3, 4};
  assert(get_majority_element(v, 0, 4) == 0);
  v = {2, 2, 3, 4, 5};
  assert(get_majority_element(v, 0, 5) == 0);
  v = {2, 2, 3, 3, 2, 2, 2, 3};
  assert(get_majority_element(v, 0, 8) == 1);
}

int main() {
  test_solution();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

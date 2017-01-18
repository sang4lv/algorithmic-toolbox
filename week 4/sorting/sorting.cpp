#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;
using std::swap;
using std::equal;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

int* partition3(vector<int> &a, int l, int r) {
  int pivot = a[l];
  int bounds[] = {l, l};

  for (int i = l + 1; i <= r; i++) {
    if (a[i] < pivot) {
      bounds[0]++;
      bounds[1]++;
      swap(a[i], a[bounds[0]]);
    } else if (a[i] == pivot) {
      bounds[1]++;
      swap(a[i], a[bounds[1]]);
    }
  }

  swap(a[l], a[bounds[0]]);
  return bounds;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  // randomize!
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  // two partitions
  // int m = partition2(a, l, r);
  // randomized_quick_sort(a, l, m - 1);
  // randomized_quick_sort(a, m + 1, r);

  // three partitions
  int* bounds = partition3(a, l, r);
  randomized_quick_sort(a, l, bounds[0] - 1);
  randomized_quick_sort(a, bounds[1] + 1, r);
}

void test_solution() {
  vector<int> v = {-1, -1, -1};
  vector<int> t = {-1, -1, -1};
  randomized_quick_sort(v, 0, v.size() - 1);
  assert(equal(v.begin(), v.end(), t.begin()));

  v = {5, 1, 7, 3, 6, 5};
  t = {1, 3, 5, 5, 6, 7};
  randomized_quick_sort(v, 0, v.size() - 1);
  assert(equal(v.begin(), v.end(), t.begin()));

  v = {5, 4, 3, 2, 1};
  t = {1, 2, 3, 4, 5};
  randomized_quick_sort(v, 0, v.size() - 1);
  assert(equal(v.begin(), v.end(), t.begin()));
}

int main() {
  test_solution();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

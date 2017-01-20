#include <vector>
#include <cassert>

using std::vector;

void merge_sort(vector<int> &a, int left, int right) {
  // base case
  if (left + 1 == right) {
    return;
  }

  // recurse
  int mid = (left + right) / 2;
  merge_sort(a, left, mid);
  merge_sort(a, mid, right);

  // merge
  int i;
  // prepare left half
  std::vector<int> v{mid - left - 1};
  for (i = 0; i < mid - left; i++) {
    v[i] = a[left + i];
  }
  i = 0;

  int j = mid;
  int k = left;
  int max_i = mid - left;

  while (i < max_i && j < right) {
    if (v[i] <= a[j]) {
      a[k++] = v[i++];
    } else {
      a[k++] = a[j++];
    }
  }
  while (i < max_i) {
    a[k++] = v[i++];
  }
}

void test_solution() {
  int size = 5;
  std::vector<int> v{5};
  v = {5, 4, 3, 2, 1};
  merge_sort(v, 0, size);

  assert(v.size() == size);
  for (int i = 1; i < size; i++) {
    assert(v[i] >= v[i - 1]);
  }
}

int main() {
  test_solution();
}

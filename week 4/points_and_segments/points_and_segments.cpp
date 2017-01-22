#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

// sort segments by ascending endpoints
// use binary search to lookup point matching the segments
int lookup(vector<vector<int>> table, int length, int a) {
  int left = 0;
  int right = length - 1;
  int count = 0;

  int mid = (left + right) / 2;
  while (left <= right) {
    if (a >= table[mid][0] && a <= table[mid][1]) {
      count++;
      break;
    } else if (a < table[mid][0]) {
      right = mid - 1;
    } else if (a > table[mid][1]) {
      left = mid + 1;
    }

    mid = (left + right) / 2;
  }

  if (count == 0) {
    return count;
  }

  int i = 1;
  while (a >= table[mid + i][0] && mid + i < length) {
    count++;
    i++;
  }

  i = -1;
  while (a <= table[mid + i][1] && mid + i > -1) {
    count++;
    i--;
  }

  // // linear lookup
  // int count = 0;
  //
  // for (int i = 0; i < length; i++) {
  //   if (a >= table[i][0] && a <= table[i][1]) {
  //     count++;
  //   } else if (count) {
  //     // assuming segments have been sorted
  //     // if a doesn't fall into this segment
  //     // and count is already non-0, there will be no further additions
  //     // so we can safely terminate early
  //     return count;
  //   }
  // }

  return count;
}

void merge_sort(vector<vector<int>> &a, int left, int right) {
  // base case
  if (left + 1 >= right) {
    return;
  }

  // recursion case
  int mid = (left + right) / 2;
  merge_sort(a, left, mid);
  merge_sort(a, mid, right);

  // prepare left half for copy
  int size = mid - left;
  vector<vector<int>> v(size, vector<int>(2));
  for (int i = 0; i < size; i++) {
    v[i] = {a[left + i][0], a[left + i][1]};
  }

  // merge
  int i = 0;
  int j = mid;
  int k = left;

  while (i < size && j < right) {
    if (v[i][1] <= a[j][1]) { // sort by ascending endpoints
      a[k++] = v[i++];
    } else {
      a[k++] = a[j++];
    }
  }
  while (i < size) {
    a[k++] = v[i++];
  }
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  int size = (int)starts.size();
  vector<int> count{size};
  vector<vector<int>> table(size, vector<int>(2));

  for (int i = 0; i < size; i++) {
    table[i] = {starts[i], ends[i]};
  }

  merge_sort(table, 0, size);

  for (int i = 0; i < size; i++) {
    count[i] = lookup(table, size, points[i]);
  }

  return count;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void test_solution() {
  vector<vector<int>> table(3, vector<int>(2));
  table = {
    {0, 2},
    {-1, 3},
    {8, 10}
  };

  assert(lookup(table, 3, 7) == 0);
  assert(lookup(table, 3, 1) == 2);
  assert(lookup(table, 3, 9) == 1);

  vector<vector<int>> v(5, vector<int>(2));
  v = {
    {5, 8},
    {6, 7},
    {5, 9},
    {7, 10},
    {1, 4},
  };
  merge_sort(v, 0, 5);

  for (int i = 1; i < 5; i++) {
    assert(v[i - 1][1] <= v[i][1]);
  }

  vector<int> starts1 = {0, 7};
  vector<int> ends1 = {5, 10};
  vector<int> points1 = {1, 6, 11};
  vector<int> counts1 = fast_count_segments(starts1, ends1, points1);
  vector<int> results1 = {1, 0, 0};
  assert(std::equal(counts1.begin(), counts1.end(), results1.begin()));

  vector<int> starts2 = {-10};
  vector<int> ends2 = {10};
  vector<int> points2 = {-100, 100, 0};
  vector<int> counts2 = fast_count_segments(starts2, ends2, points2);
  vector<int> results2 = {0, 0, 1};
  assert(std::equal(counts2.begin(), counts2.end(), results2.begin()));

  vector<int> starts3 = {0, -3, 7};
  vector<int> ends3 = {5, 2, 10};
  vector<int> points3 = {1, 6};
  vector<int> counts3 = fast_count_segments(starts3, ends3, points3);
  vector<int> results3 = {2, 0};
  assert(std::equal(counts3.begin(), counts3.end(), results3.begin()));
}

int main() {
  test_solution();

  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

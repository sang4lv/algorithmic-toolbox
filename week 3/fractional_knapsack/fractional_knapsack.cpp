#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using std::cout;
using std::vector;

vector<int> get_indices_by_value(vector<int> weights, vector<int> values) {
  size_t size = weights.size();
  vector<int> indices(size);

  // insertion sort values by max to min
  int tmp, high_proxy, high_index;
  double max = 0.0;

  for (int i = 0; i < size; i++) {
    indices[i] = i;
  }

  for (int i = 0; i < size - 1; i++) {
    high_proxy = indices[i];
    high_index = i;

    for (int j = i + 1; j < size; j++) {
      if (values[indices[j]] * 1.0 / weights[indices[j]] >
        values[high_proxy] * 1.0 / weights[high_proxy]) {
        high_proxy = indices[j];
        high_index = j;
      }
    }

    tmp = indices[high_index];
    indices[high_index] = indices[i];
    indices[i] = tmp;
  }

  return indices;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<int> indices = get_indices_by_value(weights, values);

  for (int i = 0; i < indices.size(); i++) {
    int pos = indices[i];
    if (capacity >= weights[pos]) {
      capacity -= weights[pos];
      value += values[pos];
    } else if (capacity < weights[pos]) {
      value += values[pos] * 1.0 / weights[pos] * capacity;
      capacity = 0;
      break;
    }
  }

  return value;
}

void test_solution() {
  assert(get_optimal_value(50, {20, 50, 30}, {60, 100, 120}) == 180);
  assert(get_optimal_value(50, {30}, {500}) == 500);
  char s1[10];
  char s2[10];
  sprintf(s1, "%.4f", get_optimal_value(10, {30}, {500}));
  sprintf(s2, "%.4f", 500.0 / 3);
  assert(strcmp(s1, s2) == 0);
}

int main() {
  test_solution();

  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

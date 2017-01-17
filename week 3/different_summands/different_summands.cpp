#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  if (n <= 2) {
    summands.push_back(n);
  } else {
    int l = 1;

    while (n > 2 * l) {
      summands.push_back(l);
      n -= l++;
    }

    if (n > 0) {
      summands.push_back(n);
    }
  }

  return summands;
}

void test_solution() {
  vector<int> result;

  result = optimal_summands(2);
  assert(result.size() == 1);
  assert(result[0] == 2);
  result = optimal_summands(5);
  assert(result.size() == 2);
  assert(result[0] == 1);
  assert(result[1] == 4);
  result = optimal_summands(8);
  assert(result.size() == 3);
  assert(result[0] == 1);
  assert(result[1] == 2);
  assert(result[2] == 5);
}

int main() {
  test_solution();

  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

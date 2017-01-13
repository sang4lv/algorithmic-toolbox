#include <iostream>
#include <cassert>

int get_change(int m) {
  int denom[] = {1, 5, 10};
  int index = (sizeof(denom) / sizeof(int)) - 1;
  int total = 0;

  while (m > 0) {
    if (m >= denom[index]) {
      total += m / denom[index];
      m %= denom[index];
    } else {
      index -= 1;
    }
  }

  return total;
}

void test_solution() {
  assert(get_change(0) == 0);
  assert(get_change(10) == 1);
  assert(get_change(9) == 5);
  assert(get_change(2) == 2);
  assert(get_change(28) == 6);
}

int main() {
  test_solution();

  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';

  return 0;
}

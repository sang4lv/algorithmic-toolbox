#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  return gcd_fast(b, a % b);
}

void test_solution() {
  assert(gcd_fast(1344, 217) == 7);
  assert(gcd_fast(18, 35) == 1);
  for (int n = 0; n < 20; ++n) {
    int a = rand() % 1000000;
    int b = rand() % 1000000;
    assert(gcd_fast(a, b) == gcd_naive(a, b));
  }
}

int main() {
  // test_solution();

  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << '\n';
  std::cout << gcd_naive(a, b) << '\n';

  return 0;
}

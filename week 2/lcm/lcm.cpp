#include <iostream>
#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(int a, int b) {
  int gcd = gcd_fast(a, b);

  return a / gcd * (long long)b;
}

void test_solution() {
  assert(lcm_fast(6, 8) == 24);
  assert(lcm_fast(28851538, 1183019) == 1933053046);
  for (int n = 0; n < 5; ++n) {
    int a = rand() % 100000;
    int b = rand() % 100000;
    assert(lcm_fast(a, b) == lcm_naive(a, b));
  }
}

int main() {
  // test_solution();

  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;

  return 0;
}

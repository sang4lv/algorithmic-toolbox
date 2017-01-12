#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
  if (n <= 1)
    return n;

  int previous = 0;
  int current  = 1;

  for (int i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
  if (n <= 1)
    return n;

  int a = 0;
  int b = 1;
  int c = 1;

  for (int i = 2; i <= n; i++) {
    c = (a + b) % 10;
    a = b;
    b = c;
  }

  return c % 10;
}

void test_solution() {
  assert(get_fibonacci_last_digit_fast(3) == 2);
  assert(get_fibonacci_last_digit_fast(10) == 5);
  for (int n = 0; n < 20; ++n) {
    assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
  }
}

int main() {
  // test_solution();

  int n = 0;
  std::cin >> n;
  std::cout << get_fibonacci_last_digit_naive(n) << '\n';
  std::cout << get_fibonacci_last_digit_fast(n) << '\n';

  return 0;
}

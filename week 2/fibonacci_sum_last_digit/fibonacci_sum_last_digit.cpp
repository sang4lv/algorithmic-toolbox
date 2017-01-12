#include <iostream>
#include <cassert>

int fibonacci_sum_naive(long long n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;
  long long sum      = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current;
  }

  return sum % 10;
}

int fibonacci_sum_fast(long long n) {
  if (n <= 1)
    return n;

  int a = 0;
  int b = 1;
  int c;
  int sum = 1;

  for (long long i = 2; i <= n; i++) {
    c = (a + b) % 10;
    a = b;
    b = c;
    sum = (sum + b) % 10;
  }

  return sum;
}

void test_solution() {
  assert(fibonacci_sum_fast(3) == 4);
  assert(fibonacci_sum_fast(100) == 5);
  for (int i = 0; i < 20; i++) {
    int n = rand() % 92; // since fibonacci_sum_naive will overflow after 92
    assert(fibonacci_sum_fast(n) == fibonacci_sum_naive(n));
  }

  for (int i = 0; i < 20; i++) {
    int n = rand() % 100000000000000;
    fibonacci_sum_fast(n);
  }
}

int main() {
  test_solution();

  return 0;
}

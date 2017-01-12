#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
  if (to <= 1)
    return to;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < from - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  long long sum = current;

  for (long long i = 0; i < to - from; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current;
  }

  return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
  if (to <= 1)
    return to;

  int previous = 0;
  int current  = 1;
  int sum = 0;

  for (long long i = 2; i <= to; i++) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    if (i >= from) {
      sum = (sum + current) % 10;
    }
  }

  return sum;
}

int main() {
  long long from, to;
  std::cin >> from >> to;
  std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
  return 0;
}

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::vector;
using std::string;
using std::stoi;

string largest_number(vector<string> a) {
  //write your code here
  int k;
  string temp;
  std::stringstream ret;
  size_t size = a.size();

  for (int i = 0; i < size - 1; i++) {
    k = i;
    for (int j = i + 1; j < size; j++) {
      if (stoi(a[j]) > stoi(a[k])) {
        k = j;
      }
    }

    temp = a[k];
    a[k] = a[i];
    a[i] = temp;
  }

  for (int i = 0; i < size; i++) {
    ret << a[i];
  }

  string result;
  ret >> result;
  return result;
}

void test_solution() {
  assert(largest_number({"3", "4", "2"}) == "432");
  assert(largest_number({"38", "4", "79"}) == "79384");
}

int main() {
  test_solution();

  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

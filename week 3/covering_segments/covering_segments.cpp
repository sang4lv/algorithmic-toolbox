#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cassert>

using std::vector;

struct Segment {
  int start, end;
  bool operator == (const Segment &rhs) {
    return rhs.start == this->start && rhs.end == this->end;
  }
};

void sort_segments(vector<Segment> &segments) {
  Segment s;
  int low_index;
  size_t size = segments.size();

  for (size_t i = 0; i < size - 1; ++i) {
    low_index = i;
    for (size_t j = i + 1; j < size; j++) {
      if (segments[j].end < segments[low_index].end) {
        low_index = j;
      }
    }

    s = segments[low_index];
    segments[low_index] = segments[i];
    segments[i] = s;
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  sort_segments(segments);

  vector<int> points;
  int point = segments[0].end;

  for (size_t i = 1; i < segments.size(); ++i) {
    if (segments[i].start <= point && segments[i].end >= point) {
      continue;
    } else {
      points.push_back(point);
      point = segments[i].end;
    }
  }

  points.push_back(point);

  return points;
}

void test_solution() {
  struct Segment a;
  struct Segment b;
  a.start = 2;
  a.end = 4;
  b.start = 1;
  b.end = 3;

  vector<Segment> segments = {a, b};
  sort_segments(segments);
  assert(segments[0] == b);
  assert(segments[1] == a);

  vector<int> results = optimal_points(segments);
  int size = results.size();
  assert(size == 1);
  assert(results[0] == 3);

  struct Segment c;
  struct Segment d;
  struct Segment e;
  struct Segment f;
  c.start = 4;
  c.end = 7;
  d.start = 2;
  d.end = 5;
  e.start = 1;
  e.end = 3;
  f.start = 5;
  f.end = 6;

  segments = { c, d, e, f };
  results = optimal_points(segments);
  size = results.size();
  assert(size == 2);
  for (int i = 0; i < size; i++) {
    if (results[i] != 3 && results[i] != 5 && results[i] != 6) {
      assert(false);
    }
  }
}

int main() {
  test_solution();
}

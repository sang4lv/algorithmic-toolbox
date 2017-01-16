# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

# method 1:
# sort start point in ascending fashion
# loop over segments, for each segment:
#   if there are no possible_point, get the upper bound
#   if there are possible_point, check if possible_point is within range
#     if yes, continue to next segment
#     if no, push possible_point to points and reset possible_point
# once exit loop, if possible_point is not None, then push to points

# method 2:
# setup empty array called matches
# loop over segments
#   setup lower_bound and upper_bound to match start and end of this segment
#   set Found = False initially
#   if matches is empty
#     push current segment into array and continue
#   if matches is not empty
#     loop over matches, for each segment
#       check if there is an overlap in range:
#         if so, update lower_bound and upper_bound, remove segment fron array, and mark Found = True
#         if not, push segment into matches and continue
#       if Found = True, select rightmost point and push to points
# loop over matches, for each segment
#   select leftmost point and push to points

def get_overlap_segment(s1, s2):
    assert s1.end >= s1.start
    assert s2.end >= s2.start

    if min(max(s1.end, s2.start), s2.end) == s1.end or min(max(s2.end, s1.start), s1.end) == s2.end:
        return Segment(max(s1.start, s2.start), min(s1.end, s2.end))

    return False

def optimal_points(segments):
    points = []
    matches = []

    for s in segments:
        match = Segment(s.start, s.end)
        found = False

        if len(matches):
            to_delete = []

            for i in range(len(matches)):
                result = get_overlap_segment(matches[i], match)
                if result:
                    found = True
                    match = result
                    to_delete.append(i)

            if found:
                for j in to_delete:
                    del matches[j]
                matches.append(match)
            else:
                matches.append(s)
        else:
            matches.append(s)

    for m in matches:
        points.append(m.end)

    return points

def test_solution():
    assert get_overlap_segment(Segment(1, 2), Segment(3, 4)) == False
    assert get_overlap_segment(Segment(1, 3), Segment(2, 4)) == Segment(2, 3)
    assert get_overlap_segment(Segment(1, 4), Segment(2, 3)) == Segment(2, 3)
    assert optimal_points([Segment(1, 4), Segment(2, 3)]) == [3]
    results = optimal_points([Segment(4, 7), Segment(2, 5), Segment(1, 3), Segment(5, 6)])
    assert 3 in results
    assert 5 in results or 6 in result

if __name__ == '__main__':
    test_solution()

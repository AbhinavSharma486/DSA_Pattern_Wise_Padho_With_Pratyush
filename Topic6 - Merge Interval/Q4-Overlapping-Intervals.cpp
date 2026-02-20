// * Question :- Overlapping Intervals
// & Link :- https://www.geeksforgeeks.org/problems/overlapping-intervals--174556/0

#include <iostream>
#include <vector>
using namespace std;

bool isIntersect(vector<vector<int>> &intervals)
{
  int n = intervals.size();

  // store the first interval in start1 or end1
  int start1 = intervals[0][0];
  int end1 = intervals[0][1];

  // traverse the intervals
  for (int i = 0; i < n; i++)
  {

    // store the next interval in start2 or end2
    int start2 = intervals[i][0];
    int end2 = intervals[i][1];

    // agar end1 >= start2 hai
    // iss ka matlab overlapping hai 100% hai
    if (end1 >= start2)
    {
      return true;
    }

    // agar overlapping nhi hai to
    // start1 or end1 ko update kro
    start1 = min(start1, start2);
    end1 = max(end1, end2);
  }

  return false;
}

int main()
{
  vector<vector<int>> intervals = {{1, 3}, {5, 7}, {2, 4}, {6, 8}};

  bool ans = isIntersect(intervals);

  cout << "Answer is : " << ans;

  return 0;
}
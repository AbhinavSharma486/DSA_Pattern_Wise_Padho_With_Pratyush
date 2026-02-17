// * Question :- 56 Merge Intervals
// & Link :- https://leetcode.com/problems/merge-intervals/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  int n = intervals.size();

  if (n == 0)
  {
    return {};
  }

  // Sort the intervals based on the start of the intervals
  sort(intervals.begin(), intervals.end());

  // store the result of merged intervals
  vector<vector<int>> result;

  // intervals ke first interval ke start or end ko store kr liya hai start1 and end1 me comparision ke liye
  int start1 = intervals[0][0];
  int end1 = intervals[0][1];

  // traverse the intervals
  for (int i = 1; i < n; i++)
  {
    // next interval ke start or end ko store kr liya hai start2 and end2 me comparision ke liye
    int start2 = intervals[i][0];
    int end2 = intervals[i][1];

    // agar end1 >= start 2 hai to iska matlab hai ke 100% merge hoga
    if (end1 >= start2)
    {
      start1 = min(start1, start2);
      end1 = max(end1, end2);
      continue;
    }

    // agar above if nhi chla iss ka matlab hai ke merge nhi hoga
    // to result me start1 and end1 ko push kr do
    result.push_back({start1, end1});

    // ab start1 and end1 ko update kr do next interval ke start2 and end2 se
    start1 = start2;
    end1 = end2;
  }

  // ab maan lo ke sare intervals traverse ho gye hai
  // to last me start1 and end1 ek aisa interval hai jo ke independent hai means yeh inteval ab kisi ke sath merge nhi hoga
  // to isko bhe result me push kr do
  result.push_back({start1, end1});

  return result;
};

int main()
{
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  vector<vector<int>> result = merge(intervals);

  for (int i = 0; i < result.size(); i++)
  {
    cout << "[" << result[i][0] << ", " << result[i][1] << "]";
    if (i != result.size() - 1)
    {
      cout << ", ";
    }
  }

  return 0;
}
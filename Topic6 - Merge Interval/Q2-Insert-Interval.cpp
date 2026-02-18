// * Questin :- 57. Insert Interval
// & Link :- https://leetcode.com/problems/insert-interval/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &resultedIntervals)
{
  // resulted intervals ko sort kr rhe hai
  sort(resultedIntervals.begin(), resultedIntervals.end());

  int n = resultedIntervals.size();

  if (n == 0)
  {
    return {};
  }

  vector<vector<int>> mergedIntervals;

  // resulted intervals ka start or end store kr liye hai other intervals ke sath compare krne ke liye
  int start1 = resultedIntervals[0][0];
  int end1 = resultedIntervals[0][1];

  // traverse the array
  for (int i = 1; i < n; i++)
  {
    // next interval ke start or end ko store kr liye hai star2 or end2 me
    int start2 = resultedIntervals[i][0];
    int end2 = resultedIntervals[i][1];

    // agar end1 greater than or equal to hai start2 ke to iska matlab hai ke merge hoga and 100% hoga
    if (end1 >= start2)
    {
      start1 = min(start1, start2);
      end1 = max(end1, end2);
      continue;
    }

    // agar above if condition satisfy nhi hui to iska matlab hai ke merge nhi hoga
    mergedIntervals.push_back({start1, end1});

    // ab star1 or end1 ko update kro next interval ke start or end se
    start1 = start2;
    end1 = end2;
  }

  // Edge case :
  // last interval independent hai iss ka matlab hai ke yeh interval merge nhi hoga
  // to isko bhe merged intervals me push kr do
  mergedIntervals.push_back({start1, end1});

  return mergedIntervals;
};

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
  int n = intervals.size();

  if (n == 0)
  {
    return {newInterval};
  }

  // given new interval ko insert krne ke baad jo result aayega usko store krne ke liye
  vector<vector<int>> result;

  // insert btayega ke new interval abhi tak insert hua hai ya nhi
  bool insert = false;

  // intervals ko traverse kr rhe hai ab
  for (int i = 0; i < n; i++)
  {
    // agar abhi tak inser == false hai
    // or start >= intervals[i][0] hai
    // to iska matlab hai ke ab new interval ko insert kro
    if (insert == false && newInterval[0] <= intervals[i][0])
    {
      result.push_back(newInterval);
      insert = true;
    }

    // agar above if condition satisfy nhi hui
    // to iska matlab hai ke new interval ko insert krne ke abhi need nhi pdi hai
    // to simply current interval ko result me push kro
    result.push_back(intervals[i]);
  }

  // Edge case :
  // agar new interval abhi tak insert nhi hua hai
  // to iska matlab hai ke new interval
  // ke start value greater than hai all intervals ke start value se
  // so ab iss ko result ke end me push kro
  if (insert == false)
  {
    result.push_back(newInterval);
  }

  return result;
};

int main()
{
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

  vector<int> newInterval = {4, 8};

  vector<vector<int>> result = insert(intervals, newInterval);

  vector<vector<int>> mergedResult = merge(result);

  for (int i = 0; i < mergedResult.size(); i++)
  {
    cout << "[" << mergedResult[i][0] << ", " << mergedResult[i][1] << "]";
    if (i != mergedResult.size() - 1)
    {
      cout << ", ";
    }
  }

  return 0;
}
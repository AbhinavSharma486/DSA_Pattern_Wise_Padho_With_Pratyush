// * Question :- 986. Interval List Intersections
// & Link :- https://leetcode.com/problems/interval-list-intersections/description/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &a, vector<vector<int>> &b)
{
  int n = a.size();
  int m = b.size();

  vector<vector<int>> result;

  int i = 0, j = 0;

  // 2 pointer approach
  while (i < n && j < m)
  {
    // start1 or end1 me array of a ke first list ke start or end ko store kr liya hai compare krne ke liye
    int start1 = a[i][0];
    int end1 = a[i][1];

    // start2 or end2 me array of b ke first list ke start or end ko store kr liya hai compare krne ke liye
    int start2 = b[j][0];
    int end2 = b[j][1];

    // ab hmare pass 4 option honge
    // case 1 :- ya to start1 <= start2 hoga
    // case 2 :- ya fir start2 <= start1 hoga
    // case 3 :- ya to end1 <= end2 hoga
    // case 4 :- ya fir end2 <= end1 hoga

    // case 1 :- start1 <= start2
    if (start1 <= start2)
    {
      // ab hm check krenge ke end1 >= start2 hai ya nhi
      // agar hai to iska matlab hai ke dono interval me intersection hoga
      if (end1 >= start2)
      {

        // ab hmare pass dono interval ke start or end honga
        // ab unn me se start ke max value
        // or end ke min value ko result me push krenge
        int s = max(start1, start2);
        int e = min(end1, end2);

        result.push_back({s, e});
      }
    }

    // case 2 :- start2 <= start1
    else
    {
      // ab hm check krenge ke end2 >= start1 hai ya nhi
      // agar hai to iska matlab hai ke dono interval me intersection hoga
      if (end2 >= start1)
      {

        // ab hmare pass dono interval ke start or end honge
        // ab unn me se start ke max value
        // or end ke min value ko result me push krenge
        int s = max(start1, start2);
        int e = min(end1, end2);

        result.push_back({s, e});
      }
    }

    // case 3 :- end1 <= end2
    if (end1 <= end2)
    {
      i++;
    }

    // case 4 :- end2 <= end1
    else
    {
      j++;
    }
  }

  return result;
};
int main()
{
  vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

  vector<vector<int>> result = intervalIntersection(firstList, secondList);

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
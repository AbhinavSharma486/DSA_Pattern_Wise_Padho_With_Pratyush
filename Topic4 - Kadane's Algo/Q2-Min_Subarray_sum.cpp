// * Question :- Smallest sum contiguous subarray
// & Link :- https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSumSubarray(vector<int> &a)
{
  int n = a.size();

  int minSum = a[0];
  int ans = a[0];

  for (int i = 1; i < n; i++)
  {
    int v1 = minSum + a[i];
    int v2 = a[i];

    minSum = min(v1, v2);

    ans = min(ans, minSum);
  }

  return ans;
}
int main()
{
  vector<int> nums = {3, -4, 2, -3, -1, 7, -5};

  int result = smallestSumSubarray(nums);

  cout << "The minimum subarray sum is : " << result;

  return 0;
}
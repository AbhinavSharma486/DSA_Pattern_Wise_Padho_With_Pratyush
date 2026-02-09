// * Question :- Maximum Absolute sum of any subarray
// & Link :- https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &nums)
{
  int n = nums.size();

  int i = 0;

  int bestEnding = nums[0];

  int ans = nums[0];

  for (i = 1; i < n; i++)
  {
    int v1 = bestEnding + nums[i];

    int v2 = nums[i];

    bestEnding = max(v1, v2);

    ans = max(ans, bestEnding);
  }

  return ans;
}

int minSum(vector<int> &nums)
{
  int n = nums.size();

  int i = 0;

  int bestEnding = nums[0];
  int ans = nums[0];

  for (i = 1; i < n; i++)
  {
    int v1 = bestEnding + nums[i];

    int v2 = nums[i];

    bestEnding = min(v1, v2);

    ans = min(ans, bestEnding);
  }

  return ans;
}

int maxAbsoluteSum(vector<int> &nums)
{
  int maxSUM = maxSum(nums);
  int minSUM = minSum(nums);

  int absoluteofMaxMinSum = max(abs(maxSUM), abs(minSUM));

  return absoluteofMaxMinSum;
}

int main()
{
  vector<int> nums = {2, -5, 1, -4, 3, -2};

  int result = maxAbsoluteSum(nums);

  cout << "Maximum Absolute sum of any subarray is : " << result;

  return 0;
}
// * Question :- Maximum sum circular subarray
// & Link :- https://leetcode.com/problems/maximum-sum-circular-subarray/description/?utm_source=chatgpt.com

#include <iostream>
#include <vector>
using namespace std;
// finding the max sum of subarray in non circular array using kadane's algo
int maxSubarraySumCircular(vector<int> &nums)
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

// finding the max sum of subarray in circular array using kadane's algo
int minSubarraySumCircular(vector<int> &nums)
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

  // pehle maine min sum of subarray find kiya circular array me using kadane's alg

  // finding the total sum of the array

  int totalSum = 0;

  for (int i = 0; i < n; i++)
  {
    totalSum = totalSum + nums[i];
  }

  // finding the max sum of circular subarray
  int maxSumOfCircularSubarray = totalSum - ans;

  return maxSumOfCircularSubarray;
}
int resultmaxSubarraySumCircular(vector<int> &nums)
{

  int maxSumOfNonCircularSubarray = maxSubarraySumCircular(nums);

  int minSumOfNonCircularSubarray = minSubarraySumCircular(nums);

  if (minSumOfNonCircularSubarray == 0)
  {
    return maxSumOfNonCircularSubarray;
  }

  return max(maxSumOfNonCircularSubarray, minSumOfNonCircularSubarray);
};
int main()
{
  vector<int> nums = {5, -1, -1, -6, 3};

  int result = resultmaxSubarraySumCircular(nums);

  cout << "Maximum sum circular subarray : " << result << endl;

  return 0;
}
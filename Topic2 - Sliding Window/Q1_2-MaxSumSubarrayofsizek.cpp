// * Question :- Max Sum Subarray of size k
// & Link :- https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k)
{
  int n = arr.size();

  // store the maximum sum
  int res = 0;

  int low = 0;
  int high = k - 1;
  int sum = 0;

  // calculate the sum of first k size subarray
  for (int i = 0; i <= high; i++)
  {
    sum = sum + arr[i];
  }

  // check for high not crossing the array size
  while (high < n)
  {
    // update the result if sum is greater than res
    res = max(res, sum);

    // slide the window
    low++;
    high++;

    // check for high not crossing the array size
    if (high == n)
    {
      break;
    }

    // remove the first element of previous window and add the last element of current window
    sum = sum - arr[low - 1] + arr[high];
  }

  return res;
}
int main()
{
  vector<int> arr = {100, 200, 300, 400};
  int k = 2;

  int result = maxSubarraySum(arr, k);

  cout << "Maximum sum of a subarray of size " << k << " is: " << result << endl;

  return 0;
}

// * Question :- 209. Minimum Size Subarray Sum
// & Link :- https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &nums, int target)
{
  int n = nums.size();

  int low = 0;
  int high = 0;
  int sum = 0;
  int res = INT_MAX;

  // check for hight not crossing the array size(kyuki ho skta hai ke ek he element ka subarray ho)
  while (high < n)
  {
    // abhi yha hiring ho rhi hai toh sum me add krdo
    sum = sum + nums[high];

    // check if sum is greater than or equal to target
    while (sum >= target)
    {

      // update the length of the subarray
      int len = high - low + 1;

      // update the result if len is smaller than res
      res = min(res, len);

      // sum me se low index ka element remove fire kr do
      sum = sum - nums[low];

      // slide the window from left side -> right side
      low++;
    }
    // slide the window from right side -> right side
    high++; // yha par fir hiring ho rhi hai
  }

  return res == INT_MAX ? 0 : res;
}
int main()
{
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 2;

  int result = maxSubarraySum(nums, target);

  cout << "Minimum size of a subarray with sum at least " << target << " is: " << result << endl;

  return 0;
}
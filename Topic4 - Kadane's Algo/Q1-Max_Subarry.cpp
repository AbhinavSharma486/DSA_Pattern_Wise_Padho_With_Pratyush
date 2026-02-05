// * Question :- 53. Maximum Subarray
// & Link :- https://leetcode.com/problems/maximum-subarray/description/?utm_source=chatgpt.com

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
  int n = nums.size();

  int i = 0;

  // starting me bestEnding arr[0] he hota hai
  int bestEnding = nums[0];

  // starting me ans arr[0] he hota hai
  int ans = nums[0];

  // traversing the array
  // uss ke baad har ek index pr 2 choice hoti hai
  // 1st one ke prev. bestEnding + nums[i] ya to yeh kr ke max sum nikal lo
  // 2nd one is ke only nums[i] he max sum hoga
  for (i = 1; i < n; i++)
  {
    // 1st choice
    int v1 = bestEnding + nums[i];

    // 2nd choice
    int v2 = nums[i];

    // bestEnding me max of v1 and v2 store kro
    bestEnding = max(v1, v2);

    // ans me max of prev. ans and curr. bestEnding store kro
    ans = max(ans, bestEnding);
  }

  return ans;
}
int main()
{
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int result = maxSubArray(nums);

  cout << "The maximum subarray sum is : " << result;

  return 0;
}





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
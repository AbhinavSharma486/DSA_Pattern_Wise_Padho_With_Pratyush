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


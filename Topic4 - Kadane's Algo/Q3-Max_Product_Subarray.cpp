// * Question :- 152. Maximum Product Subarray
// & Link :- https://leetcode.com/problems/maximum-product-subarray/description/?utm_source=chatgpt.com

#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums)
{
  int n = nums.size();

  // pehle wali max ending store hogi iss me
  int maxEnding = nums[0];

  // pehle wali min ending store hogi iss me
  int minEnding = nums[0];

  // iss me pehle wala ans store hoga
  int ans = nums[0];

  // traverse the array
  // then har ek index pr 3 choice hogi
  // 1st choce ke prev. maxEnding * nums[i]
  // 2nd choice ke prev. minEnding * nums[i]
  // 3rd choice ke nums[i]
  for (int i = 1; i < n; i++)
  {
    int v1 = maxEnding * nums[i];
    int v2 = minEnding * nums[i];
    int v3 = nums[i];

    // updating the maxEnding
    maxEnding = max(v1, max(v2, v3));

    // updating the minEnding
    minEnding = min(v1, min(v2, v3));

    // updating the ans
    ans = max(ans, max(maxEnding, minEnding));
  }

  return ans;
};
int main()
{
  vector<int> nums = {2, 3, -2, 4};

  int result = maxProduct(nums);

  cout << "The maximum product subarray is : " << result;

  return 0;
}
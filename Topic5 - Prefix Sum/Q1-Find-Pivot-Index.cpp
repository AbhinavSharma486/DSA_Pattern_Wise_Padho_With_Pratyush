// * Question :- 724. Find Pivot Index
// & Link :- https://leetcode.com/problems/find-pivot-index/description/

#include <iostream>
#include <vector>
using namespace std;
int pivotIndex(vector<int> &nums)
{
  int n = nums.size();

  int left = 0;
  int right = 0;

  // find the total sum of given array
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + nums[i];
  }

  // traverse the array
  for (int i = 0; i < n; i++)
  {
    right = sum - nums[i] - left;

    if (left == right)
    {
      return i;
    }

    left = left + nums[i];
  }

  return -1;
}
int main()
{
  vector<int> nums = {1, 1, 1};

  int ans = pivotIndex(nums);

  cout << "Pivot Index is : " << ans;

  return 0;
}
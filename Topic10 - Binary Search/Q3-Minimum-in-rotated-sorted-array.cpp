// * Question :- 153. Find Minimum in Rotated Sorted Array
// & Link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums)
{
  int n = nums.size();

  int low = 0;
  int high = n - 1;

  int res = -1;

  while (low <= high)
  {
    int guess = (low + high) / 2;

    if (nums[guess] > nums[n - 1]) // part 2
    {
      low = guess + 1;
    }
    else // part 1
    {
      res = guess;
      high = guess - 1;
    }
  }

  return nums[res];
}
int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  int result = findMin(nums);

  cout << "The minimum element in the rotated sorted array is : " << result;

  return 0;
}
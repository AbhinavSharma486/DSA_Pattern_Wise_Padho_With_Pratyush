// * Question :- 704. Binary Search
// & Link :- https://leetcode.com/problems/binary-search/description/

#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &nums, int target)
{
  int n = nums.size();

  int low = 0, high = n - 1;

  while (low <= high)
  {
    int guess = (low + high) / 2;

    if (nums[guess] == target)
    {
      return guess;
    }
    else if (nums[guess] < target)
    {
      low = guess + 1;
    }
    else
    {
      high = guess - 1;
    }
  }

  return -1;
}
int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;

  int result = search(nums, target);

  cout << "Output: " << result;

  return 0;
}
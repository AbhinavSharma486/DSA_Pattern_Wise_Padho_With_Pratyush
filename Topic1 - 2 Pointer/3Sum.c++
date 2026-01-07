#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
  int n = nums.size();

  // sort the array
  sort(nums.begin(), nums.end());

  // to store the answer
  vector<vector<int>> ans;

  // traverse the array
  for (int i = 0; i < n - 2; i++)
  {
    // skip the duplicates
    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }

    int left = i + 1;
    int right = n - 1;
    int sum = -1 * nums[i];

    // two pointer approach
    while (left < right)
    {
      // found the triplet
      if (nums[left] + nums[right] == sum)
      {
        ans.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;

        // skip the duplicates for left pointer
        while (left < right && nums[left] == nums[left - 1])
        {
          left++;
        }

        // skip the duplicates for right pointer
        while (left < right && nums[right] == nums[right + 1])
        {
          right--;
        }
      }

      // move the left pointer to the right
      else if (nums[left] + nums[right] < sum)
      {
        left++;
      }

      // move the right pointer to the left
      else
      {
        right--;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = threeSum(nums);

  for (const auto &triplet : result)
  {
    cout << "[";
    for (size_t i = 0; i < triplet.size(); i++)
    {
      cout << triplet[i];
      if (i < triplet.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}
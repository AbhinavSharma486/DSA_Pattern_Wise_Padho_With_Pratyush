// & Question :- 3 Sum
// * Brute Force Approach :-

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

  int i, j, k;

  // traverse the array
  for (i = 0; i < n; i++)
  {
    // skip the duplicates for i
    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }

    for (j = i + 1; j < n; j++)
    {
      for (k = j + 1; k < n; k++)
      {
        if (nums[i] + nums[j] + nums[k] == 0)
        {
          ans.push_back({nums[i], nums[j], nums[k]});
        }
      }

      // skip the duplicates for j
      while (j + 1 < n && nums[j] == nums[j + 1])
      {
        j++;
      }

      // skip the duplicates for k
      while (k + 1 < n && nums[k] == nums[k + 1])
      {
        k++;
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

// T.C = O(N^3)
// S.C = O(1)

// * Optimal Approach :-

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
    // skip the duplicates for i
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

// T.C = O(N^2)
// S.C = O(1)

// & Question :- 3 Sum closest
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
  int n = nums.size();

  // sort the array
  sort(nums.begin(), nums.end());

  // bestDiff me smallest difference store hoga ab tak ka
  int bestDiff = INT_MAX;

  // bestSum me closest sum store hoga ab tak ka
  int bestSum = 0;

  // traverse the array
  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1;
    int right = n - 1;

    // two pointer approach
    while (left < right)
    {
      // calculate the sum of three current elements
      int currentSum = nums[i] + nums[left] + nums[right];

      // calculate the difference between target and current sum
      int currentDiff = abs(target - currentSum);

      // check kro ki current sum target ke kitne close hai
      if (currentDiff < bestDiff)
      {
        // update the best difference
        bestDiff = currentDiff;

        // update the best sum
        bestSum = currentSum;
      }

      // agar exact target mil jata hai to turant return kar do
      if (currentSum == target)
      {
        return bestSum;
      }

      // agar sum target se chhota hai to left pointer ko aage badhao
      else if (currentSum < target)
      {
        left++;
      }
      else // agar sum target se bada hai to right pointer ko peeche le jao
      {
        right--;
      }
    }
  }

  return bestSum;
}
int main()
{
  vector<int> nums = {0, 0, 0};
  int target = 1;

  int result = threeSumClosest(nums, target);

  cout << "The sum that is closes to the target is : " << result << endl;

  return 0;
}
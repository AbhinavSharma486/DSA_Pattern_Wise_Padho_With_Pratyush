// & Leetcode link :- https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Time Complexity : O(n) ✅
// Space Complexity : O(n) ❌ (extra vectors ki wajah se)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> squareOfSortedArray(vector<int> &nums)
{
  int nsiz = nums.size();

  vector<int> neg;
  vector<int> pos;

  // dividing the array into negative and positive parts
  for (int i = 0; i < nsiz; i++)
  {
    if (nums[i] >= 0) // positive part
    {
      pos.push_back(nums[i]);
    }
    else // negative part
    {
      neg.push_back(nums[i]);
    }
  }

  // Edge case: no negative elements
  if (neg.size() == 0)
  {
    for (int i = 0; i < pos.size(); i++)
    {
      pos[i] = pos[i] * pos[i];
    }

    return pos;
  }

  // Edge case: no positive elements
  if (pos.size() == 0)
  {
    for (int i = 0; i < neg.size(); i++)
    {
      neg[i] = neg[i] * neg[i];
    }

    reverse(neg.begin(), neg.end());

    return neg;
  }

  // merge neg and pos into nums
  nums.clear();

  int i = 0, j = 0;
  int id = 0;
  int n = neg.size();
  int m = pos.size();

  vector<int> res(n + m);

  // squaring the negative part and reversing it
  for (int i = 0; i < n; i++)
  {
    neg[i] = neg[i] * neg[i];
  }

  reverse(neg.begin(), neg.end());

  // squaring the positive part and return it
  for (int i = 0; i < m; i++)
  {
    pos[i] = pos[i] * pos[i];
  }

  // merging two sorted arrays starts here
  while (i < n && j < m)
  {
    if (neg[i] < pos[j])
    {
      res[id] = neg[i];
      id++;
      i++;
    }
    else
    {
      res[id] = pos[j];
      id++;
      j++;
    }
  } // merging two sorted arrays ends here

  while (i < n)
  {
    res[id] = neg[i];
    id++;
    i++;
  }

  while (j < m)
  {
    res[id] = pos[j];
    id++;
    j++;
  }

  return res;
}

int main()
{
  vector<int> nums = {-4, -1, 0, 3, 10};

  vector<int> result = squareOfSortedArray(nums);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}




// * Method 2 (Optimized) :- Two Pointer Approach
// Time Complexity : O(n) ✅
// Space Complexity : O(n) ✅ (no extra vectors)

#include <iostream>
#include <vector>
using namespace std;

vector<int> squareOfSortedArray(vector<int> &nums)
{
  int n = nums.size();

  vector<int> res(n);

  int left = 0;
  int right = n - 1;
  int idx = n - 1;

  while (left <= right)
  {
    int leftSqr = nums[left] * nums[left];
    int rightSqr = nums[right] * nums[right];

    if (leftSqr > rightSqr)
    {
      res[idx] = leftSqr;
      left++;
    }
    else
    {
      res[idx] = rightSqr;
      right--;
    }
    idx--;
  }

  return res;
}

int main()
{
  vector<int> nums = {-4, -1, 0, 3, 10};

  vector<int> result = squareOfSortedArray(nums);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}
// * Questions :- 424. Longest Repeating Character Replacement
// & Link :- https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int find(vector<int> &a)
{
  int maxcount = -1;
  for (int i = 0; i < 256; i++)
  {
    maxcount = max(maxcount, a[i]);
  }

  return maxcount;
}

int characterReplacement(string s, int k)
{
  int n = s.size();

  // store the count of each char in the array
  vector<int> f(256, 0);

  int low = 0;
  int high = 0;
  int res = INT_MIN;

  for (high = 0; high < n; high++)
  {
    // high ko include / freq. inc. kro
    f[s[high]]++;

    // calculate the length of current window
    int len = high - low + 1;

    // find the max freq. char in current window
    int maxcount = find(f);

    // calculate the number of chars to be replaced in current window
    int diff = len - maxcount;

    // if diff is greater than k
    while (diff > k) // shrink window
    {
      // low pointer char ke freq. dec. kro
      f[s[low]]--;

      low++; // slide window

      // recalculate max count freq.
      maxcount = find(f);

      // recalculate len
      len = high - low + 1;

      // recalculate diff
      diff = len - maxcount;
    }

    // diff is equal or less than k then update len and also update res
    len = high - low + 1;

    res = max(res, len);
  }

  return res;
};
int main()
{
  string s = "AABABBA";
  int k = 1;

  int result = characterReplacement(s, k);

  cout << "The longest substring with repeating chars is : " << result;

  return 0;
}

// * Questions :- 1004. Max Consecutive Ones III
// & Link :- https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
  int n = nums.size();

  vector<int> f(2, 0);

  int low = 0;
  int high = 0;
  int res = INT_MIN;

  for (high = 0; high < n; high++)
  {
    // high ko include / freq. inc. kro
    f[nums[high]]++;

    // calculate the length of current window
    int len = high - low + 1;

    // find the max freq. in current window
    int maxcount = f[1];

    // calculate the number of 0's and 1's to be replaced in current window
    int diff = len - maxcount;

    while (diff > k)
    {
      // low pointer ke freq. dec. kro
      f[nums[low]]--;

      low++; // slide window

      // recalculate max count freq.
      maxcount = f[1];

      // recalculate len of curr. window
      len = high - low + 1;

      // recalculate diff
      diff = len - maxcount;
    }

    // diff is equal or less than k then update len and also update res
    // recalculate len of current window
    len = high - low + 1;

    res = max(res, len);
  }

  return res;
};
int main()
{
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  int result = longestOnes(nums, k);

  cout << "The longest substring with repeating 1's is : " << result;

  return 0;
}
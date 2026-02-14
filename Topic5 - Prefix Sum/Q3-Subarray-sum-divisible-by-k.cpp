// * Question :- Subarray Sum Divisible by k
// & Link :-https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
  int n = nums.size();

  int sum = 0;
  int res = 0;
  unordered_map<int, int> f;
  f[0] = 1;

  for (int i = 0; i < n; i++)
  {
    // curr. element ko add kro sum me
    sum = sum + nums[i];

    // ab sum ka remainder nikala k se
    int rem = sum % k;

    // agar rem negative hai to usko positive me convert kro
    if (rem < 0)
    {
      rem = rem + k;
    }

    // ab check kro ke f me rem exists krta hai ya nhi / uski freq. inc. kro
    res = res + f[rem];

    // curr. rem ki freq. inc. kro hashmap me
    f[rem]++;
  }

  return res;
}

int main()
{
  vector<int> nums = {4, 5, 0, -2, -3, 1};
  int k = 5;

  int result = subarraysDivByK(nums, k);

  cout << "Thare are " << result << " subarrays with a sum divisibele by k = " << k;

  return 0;
}
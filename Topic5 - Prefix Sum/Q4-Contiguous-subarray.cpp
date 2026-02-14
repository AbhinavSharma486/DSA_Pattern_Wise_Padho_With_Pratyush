// * Question :- 525. Contiguous Array
// & Link :- https://leetcode.com/problems/contiguous-array/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findMaxLength(vector<int> &nums)
{
  int n = nums.size();

  unordered_map<int, int> f;

  int zero = 0;
  int one = 0;

  int res = 0;

  for (int i = 0; i < n; i++)
  {
    // agar nums[i] 0 hai to zero ka count inc. hoga
    if (nums[i] == 0)
    {
      zero++;
    }
    else // otherwise one ka count inc. hoga
    {
      one++;
    }

    // ab hmne zero aur one ka count ka diff. nikal liya hai
    int diff = zero - one;

    // agar diff. 0 ho jaye to result me max of prev. result and i : curr. index + 1(1 based indexing)
    if (diff == 0)
    {
      res = max(res, i + 1);
      continue;
    }

    //  ab hm check krenge hashmap me ke kya yeh diff. pehle se exists karta hai ya nhi
    if (f.find(diff) == f.end()) // hashmap me hai ya nhi yeh pta chlega yha se
    {
      // agar nhi hai to iss ka index store kro hashmap me 
      f[diff] = i;
    }
    else
    { // iss ka matlab hai ke yeh diff. pehle se exist karta hai

      // to hm check krenge ke iss diff. ka index kya hai hashmap me
      int idx = f[diff];

      // ab hmare pass do index hai : ek current index i aur dusra index idx jaha pe yeh diff. pehle se exist karta hai
      int len = i - idx;

      // ab result ko update krlo max of prev. result and current length of good subarray which is [i - idx]
      res = max(res, len);
    }
  }

  return res;
};
int main()
{
  vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};

  int result = findMaxLength(nums);

  cout << "The maximum length of a contiguous array with equal number of 0s and 1s is : " << result;

  return 0;
}
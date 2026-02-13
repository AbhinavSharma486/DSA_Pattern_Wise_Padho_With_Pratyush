// * Question :- 560. Subarray Sum Equals K
// & Link :- https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
  int n = nums.size();

  // hashmap me har ek sum ke freq. store hogi
  unordered_map<int, int> prefixSumFreq;

  int sum = 0;
  int count = 0;

  // Base case :
  // agar kisi index tak ka prefix sum hi k ke equal ho jaye to
  // sum - k = 0 hoga
  // iss liye prefix sum 0 ke freq. ko 1 se set kar dete hai
  prefixSumFreq[0] = 1;

  // traverse the array
  for (int i = 0; i < n; i++)
  {
    // curr. element ko prefix sum me add karte hai
    sum = sum + nums[i];

    // hme ab check krna hai ke kya koi previous prefix sum exists krta hai
    // jisse subtract krne par current sum ke ke equal ho jaye
    // matlab : previous_prefix_sum = sum - k
    int ques = sum - k;

    // check if the prefix sum exists in the hashmap
    int freq = prefixSumFreq[ques];

    // agar exists krta hai to uski freq. ko count me add kro
    count = count + freq;

    // ab curr. prefix sum ki freq. ko hashmap me update krte hai
    prefixSumFreq[sum]++;
  }

  return count;
};
int main()
{
  vector<int> nums = {1, 1, 1};
  int k = 2;

  int result = subarraySum(nums, k);

  cout << "Number of subarrays that sum to " << k << " : " << result << endl;

  return 0;
}
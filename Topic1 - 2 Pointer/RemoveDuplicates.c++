// & Leetcode Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
    return 0;

  int officer = 0;
  int res = 1;
  int cm = 1;

  while (cm < n)
  {
    if (nums[cm] != nums[cm - 1])
    {
      officer++;
      nums[officer] = nums[cm];
      res++;
    }
    cm++;
  }
  return res;
}

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int k = removeDuplicates(nums);

  cout << "The length of the array after removing duplicates is: " << k << endl;
}



// Revision of above code
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();

  int officer = 0;
  int cm = 1;
  int res = 1;

  while (cm < n)
  {
    if (nums[cm] != nums[cm - 1])
    {
      nums[officer + 1] = nums[cm];
      officer++;
      cm++;
      res++;
    }
    else
    {
      cm++;
    }
  }
  return res;
}

int main()
{
  vector<int> nums = {1, 1, 2};

  int k = removeDuplicates(nums);

  cout << "The length of the array after removing duplicates is: " << k << endl;
}
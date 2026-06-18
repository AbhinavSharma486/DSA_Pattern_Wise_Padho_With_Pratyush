// * Question :- 852. Peak Index in a Mountain Array
// & Link :- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
  int n = arr.size();

  int low = 0, high = n - 1;

  while (low <= high)
  {
    int guess = (low + high) / 2;

    if (arr[guess] > arr[guess + 1] && arr[guess] > arr[guess - 1])
    {
      return guess;
    }
    else if (arr[guess] < arr[guess + 1])
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
  vector<int> nums = {0, 10, 5, 2};

  int result = peakIndexInMountainArray(nums);

  cout << "Peak Index in Mountain Array : " << result;

  return 0;
}
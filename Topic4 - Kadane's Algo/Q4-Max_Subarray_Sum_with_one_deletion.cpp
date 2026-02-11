// * Question :- 1186. Maximum Subarray Sum with One Deletion
// & Link :- https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maximumSum(vector<int> &arr)
{
  int n = arr.size();

  // Edge case : if array has only one element
  if (n == 1)
  {
    return arr[0];
  }

  // Step 1 :
  // noDelete : max Subarray sum ending at curr. idx. without any deletion
  // oneDelete : max Subarray sum ending at curr. idx. with one deletion

  int noDelete = arr[0];
  int oneDelete = INT_MIN;
  int result = arr[0];

  // Traverse the array
  for (int i = 1; i < n; i++)
  {
    // store the previous values before updaing
    int prevNoDelete = noDelete;
    int prevOneDelete = oneDelete;

    // Step 2 : Update noDelete
    // case 1 : extend the previous subarray with curr. element : prevNoDelete + arr[i];
    // case 2 : start fresh from curr. element : arr[i];

    noDelete = max(prevNoDelete + arr[i], arr[i]);

    // Step 3 : Update oneDelete
    // case 1 : we already deleted earlier then extend that subarray : prevOneDelete + arr[i];
    // case 2 : we can delete curr. element so we take previous noDelete : prevNoDelete;

    // means we have not used deletion before,
    // so only option is to delete the curr. element
    if (prevOneDelete == INT_MIN)
    {
      oneDelete = prevNoDelete; // here we are deleting the curr. element
    }
    else
    {
      oneDelete = max(prevOneDelete + arr[i], prevNoDelete);
    }

    // Step 4 : Update result
    result = max(result, max(noDelete, oneDelete));
  }

  return result;
}
int main()
{
  vector<int> arr = {1, -2, 0, 3};

  int result = maximumSum(arr);

  cout << "Maximum subarray sum with one deletion : " << result;

  return 0;
}
// * Question :- 1186. Maximum Subarray Sum with One Deletion
// & Link :- https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maximumSum(vector<int> &arr)
{
  int n = arr.size();

  // noDelete : max. sum of subarray ending at curr. index with no deletion
  int noDelete = arr[0];

  // oneDelete : max. sum of subarray ending at curr. index with one deletion
  int oneDelete = INT_MIN;

  // result : stores the overall max. sum of subarray with at most one deletion
  int result = arr[0];

  // traverse the array from idx 1
  for (int i = 1; i < n; i++)
  {
    // store previous noDelete before updating
    int prevNoDelete = noDelete;

    // store the previous oneDelete before updating
    int prevOneDelete = oneDelete;

    // update noDelete
    // either noDelete + arr[i] or arr[i] at curr. index
    noDelete = max(noDelete + arr[i], arr[i]);

    int v2;

    // if no subarray with one deletion existed before,
    // we cannot extend it, so start fresh from curr. element
    if (prevOneDelete == INT_MIN)
    {
      v2 = arr[i];
    }

    // otherwise, extend the previous one delete subarray by adding the curr. element
    else
    {
      v2 = prevOneDelete + arr[i];
    }

    // now update oneDelete
    // max of v2 and prevNoDelete(here curr. element is prevNoDelete)
    oneDelete = max(v2, prevNoDelete);

    // update the overall result
    result = max(result, max(oneDelete, noDelete));
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
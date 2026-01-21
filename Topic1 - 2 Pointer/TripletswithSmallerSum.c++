// * Question :- Triplets with Smaller Sum
// & Link :- https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

#include <iostream>
#include <algorithm>
using namespace std;
long long countTriplets(int n, int sum, int arr[])
{
  // sort the array
  sort(arr, arr + n);

  // Initialize result
  int count = 0;

  // Traverse the array
  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1;
    int right = n - 1;

    while (left < right)
    {
      // Calculate current sum
      int s = arr[i] + arr[left] + arr[right];

      // If sum is greater than or equal to given sum
      if (s >= sum)
      {
        right--;
      }
      else
      {
        // If sum is smaller than given sum (main condition to find the triplets)
        count = count + (right - left);
        left++;
      }
    }
  }

  return count;
}
int main()
{
  int n = 4;
  int sum = 2;
  int arr[] = {-2, 0, 1, 3};

  cout << "Count of triplets is " << countTriplets(n, sum, arr);
  return 0;
}
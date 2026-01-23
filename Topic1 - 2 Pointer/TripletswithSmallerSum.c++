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

// Revision of above code
#include <iostream>
#include <algorithm>
using namespace std;
long long countTriplets(int n, int sum, int arr[])
{
  // sort the array
  sort(arr, arr + n);

  // store the count of triplets
  int count = 0;

  // traverse the array
  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1;
    int right = n - 1;

    // two pointer approach
    while (left < right)
    {
      int s = arr[i] + arr[left] + arr[right];

      // if sum is greater than or equal to given sum
      if (s >= sum)
      {
        right--;
      }
      else
      { // if sum is smaller than given sum
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

// * Question :- Dutch National Flag Problem
// & Link :- https://leetcode.com/problems/sort-colors/
// ^ Method 1 :- Brute force approach

#include <iostream>
#include <vector>
using namespace std;
vector<int> sortColors(vector<int> &nums)
{
  int n = nums.size();

  vector<int> zero;
  vector<int> one;
  vector<int> two;

  // traverse the given vector
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
    {
      zero.push_back(0);
    }
    else if (nums[i] == 1)
    {
      one.push_back(1);
    }
    else
    {
      two.push_back(2);
    }
  }

  // clear the given vector
  nums.clear();

  // insert all 0's in the given vector
  for (int i = 0; i < zero.size(); i++)
  {
    nums.push_back(0);
  }

  // insert all 1's in the given vector
  for (int i = 0; i < one.size(); i++)
  {
    nums.push_back(1);
  }

  // inset all 2's in the given vector
  for (int i = 0; i < two.size(); i++)
  {
    nums.push_back(2);
  }

  return nums;
}
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> result = sortColors(nums);

  cout << "Sorted array is : ";

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}

// ^ Method 2 :- Optimal approach

#include <iostream>
#include <vector>
using namespace std;
vector<int> sortColors(vector<int> &nums)
{
  int n = nums.size();

  int zero = 0, one = 0, two = 0;

  // traverse the given vector
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
    {
      zero++;
    }
    else if (nums[i] == 1)
    {
      one++;
    }
    else
    {
      two++;
    }
  }

  // clear the given vector
  nums.clear();

  // insert all 0's in the given vector
  for (int i = 0; i < zero; i++)
  {
    nums.push_back(0);
  }

  // insert all 1's in the given vector
  for (int i = 0; i < one; i++)
  {
    nums.push_back(1);
  }

  // inset all 2's in the given vector
  for (int i = 0; i < two; i++)
  {
    nums.push_back(2);
  }

  return nums;
}
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> result = sortColors(nums);

  cout << "Sorted array is : ";

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}

// ^ Method 3 :- Best Approach (2 Pointer Approach with Dutch National Flag Algorithm)
#include <iostream>
#include <vector>
using namespace std;
vector<int> sortColors(vector<int> &nums)
{
  int n = nums.size();

  int low = 0, mid = 0, high = n - 1;

  while (mid <= high)
  {
    if (nums[mid] == 0)
    {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }
    else if (nums[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(nums[mid], nums[high]);
      high--;
    }
  }

  return nums;
}
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> result = sortColors(nums);

  cout << "Sorted array is : ";

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}

// Revision of above code

#include <iostream>
#include <vector>
using namespace std;
vector<int> sortColors(vector<int> &nums)
{
  int n = nums.size();

  int low = 0, mid = 0, high = n - 1;

  // two pointer approach
  while (mid <= high)
  {
    if (nums[mid] == 0)
    {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }

    else if (nums[mid] == 1)
    {
      mid++;
    }

    else
    {
      swap(nums[mid], nums[high]);
      high--;
    }
  }

  return nums;
}
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> result = sortColors(nums);

  cout << "Sorted array is : ";

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}
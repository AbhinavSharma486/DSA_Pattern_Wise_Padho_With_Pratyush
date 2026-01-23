// & Leetcode link :- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
  int n = numbers.size();
  int i = 0, j = n - 1;

  while (i < j)
  {
    int sum = numbers[i] + numbers[j];

    if (sum == target)
    {
      return {i + 1, j + 1}; // 1 based indexing
    }
    else if (sum < target)
    {
      i++;
    }
    else
    {
      j--;
    }
  }

  return {};
}
int main()
{
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  vector<int> result = twoSum(numbers, target);

  cout << "Indices: " << result[0] << ", " << result[1] << endl;

  cout << numbers[result[0] - 1] << " + " << numbers[result[1] - 1] << " = " << target << endl;

  return 0;
}




// Revision of above code
#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
  int n = numbers.size();

  // left or right pointers
  int left = 0, right = n - 1;

  // two pointer approach start here
  while (left < right)
  {
    int sum = numbers[left] + numbers[right];

    if (sum == target)
    {
      return {left + 1, right + 1}; // 1 based indexing
    }
    else if (sum < target)
    {
      left++;
    }
    else
    { // sum > target
      right--;
    }
  }

  return {};
}
int main()
{
  vector<int> numbers = {2, 5, 1, 7, 3};
  int target = 6;

  vector<int> result = twoSum(numbers, target);

  cout << "Indices: " << result[0] << ", " << result[1] << endl;

  cout << numbers[result[0] - 1] << " + " << numbers[result[1] - 1] << " = " << target << endl;

  return 0;
}
// * Question :- 287. Find the Duplicate Number
// & Link :- https://leetcode.com/problems/find-the-duplicate-number/description/

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
  int slow = 0;
  int fast = 0;

  while (true)
  {
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];

    // agar slow == fast ho gya hai iss ka matlab hai ke cycle hai and ab dono slow and fast meeting point pr hai
    if (slow == fast)
    {
      // slow ko 0 pr leke chalna hai
      slow = 0;

      // jab tak slow and fast ek sath nhi milte hai jab tak loop chalega
      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[fast];
      }

      // ab slow and fast ek sath cycle ke starting point pr hai ab slow ko return krdo
      return slow;
    }
  }

  return 0;
}

int main()
{
  vector<int> nums = {1, 3, 4, 2, 2};

  int result = findDuplicate(nums);

  cout << "The duplicate number is : " << result;

  return 0;
}






// * Question :- 202. Happy Number
// & Link :- https://leetcode.com/problems/happy-number/description/

#include <iostream>
using namespace std;

// yeh function sum of square of digits return krta hai
int squareSum(int n)
{
  int sum = 0;

  while (n > 0)
  {
    int d = n % 10;
    n = n / 10;
    sum = sum + d * d;
  }

  return sum;
}

bool isHappy(int n)
{
  int slow = n;
  int fast = n;

  // jab tak fast not equal to 1 hai tab tak yeh loop chlega
  while (fast != 1)
  {
    // slow ko 1 step inc. kro
    slow = squareSum(slow);

    // fast ko 2 step inc. kro
    fast = squareSum(fast);
    fast = squareSum(fast);

    // agar slow == fast ho gya hai iss ka matlab hai ke cycle exist krta hai
    // and slow != 1 hai iss ka matlab hai ke koi bhe no. 1 nhi bna hai
    if (slow == fast && slow != 1)
    {
      return false;
    }
  }

  // yha tak aane ka matlab hai ke fast == 1 ban gya hai and ab return kro true
  return true;
}

int main()
{
  int n = 19;

  if (isHappy(n))
  {
    cout << "The number is happy";
  }
  else
  {
    cout << "The number is not happy";
  }

  return 0;
}
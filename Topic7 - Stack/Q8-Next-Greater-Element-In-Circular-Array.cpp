// * Question :- 503. Next Greater Element II
// & Link :- https://leetcode.com/problems/next-greater-element-ii/description/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElementInCircularArray(vector<int> &nums)
{
  int n = nums.size();

  vector<int> res(n);

  // stack create kiya or stack me elements push kiye
  // given array ke last se first tak stack me elements push kr diye hai
  // taki her ek element ko chance mile ke next greater element find krne ke
  stack<int> st;
  for (int i = n - 2; i >= 0; i--)
  {
    st.push(nums[i]);
  }

  // traverse the array from last to first
  for (int i = n - 1; i >= 0; i--)
  {
    // jab tak stack empty nhi ho jata hai
    // tab tak yeh dekho ke stack ke top me nums[i] se chote/smaller jo
    // elements hai unko pop out kro
    while (!st.empty() && st.top() <= nums[i])
    {
      st.pop();
    }

    // agar stack emtpy hai to res[i] = -1 push kro
    if (st.empty())
    {
      res[i] = -1;
    }

    // agar stack empty nhi hai to res[i] = stack ka top push kro
    else
    {
      res[i] = st.top();
    }

    // current element stack me push kro
    st.push(nums[i]);
  }
  return res;
};
int main()
{
  vector<int> nums = {1, 2, 3, 4, 3};

  vector<int> result = nextGreaterElementInCircularArray(nums);

  cout << "[ ";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ", ";
  }
  cout << "]";

  return 0;
}
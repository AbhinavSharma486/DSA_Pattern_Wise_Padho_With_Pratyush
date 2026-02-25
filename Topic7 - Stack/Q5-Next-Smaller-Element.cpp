// * Question :- Next Smaller Element

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> nums)
{
  int n = nums.size();

  // stack me smaller elements ko store krenge
  stack<int> st;
  // stack me array ka last index ka element push kr diya hai
  st.push(nums[n - 1]);

  // res vector result array store krne ke liye
  vector<int> res(n);
  // result array ke last index pr -1 push kr diya hai
  res[n - 1] = -1;

  // traverse the array from last to first
  for (int i = n - 2; i >= 0; i--)
  {
    // jab tak stack empty nhi ho jata
    // tab tak stack ke top se vo elements pop kro jo nums[i] se bda/greater hai
    while (!st.empty() && st.top() >= nums[i])
    {
      st.pop();
    }

    // agar stack empty hai to result array me -1 store kro
    if (st.empty())
    {
      res[i] = -1;
    }

    // iss ka matlab hai ke stack ke top me nums[i] se chota element hai uss ko result array me push kro
    else
    {
      res[i] = st.top();
    }

    // current element ko stack me push kro pta nhi chalta kb kaam aa jaye
    st.push(nums[i]);
  }

  return res;
}
int main()
{
  vector<int> nums = {4, 1, 2, 5, 3};

  vector<int> result = nextSmallerElement(nums);

  cout << "[ ";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << "]";

  return 0;
}
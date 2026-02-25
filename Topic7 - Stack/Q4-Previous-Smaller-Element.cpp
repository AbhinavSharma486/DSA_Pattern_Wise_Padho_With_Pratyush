// * Question :- Previous Smaller Element

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> previousSmallerElement(vector<int> nums)
{
  int n = nums.size();

  // res vector result array store krne ke liye
  vector<int> res(n);

  // result me first element ka prev greater -1 hoga
  res[0] = -1;

  // stack me prev smaller element store krne ke liye
  stack<int> st;

  // stack me first element push kr diya hai
  st.push(nums[0]);

  // traverse the given array
  for (int i = 0; i < n; i++)
  {
    // jab tak stack empty nhi ho jata hai
    // tab tak stack ka top check krte rho ke nums[i] se big or equal elements ko pop krte rho
    while (!st.empty() && st.top() >= nums[i])
    {
      st.pop();
    }

    // agar stack empty hai to result me -1 push kro
    if (st.empty())
    {
      res[i] = -1;
    }

    // iss ka matlab hai ke stack ke top me smaller element hai
    // so result me stack ka smaller element push kro
    else
    {
      res[i] = st.top();
    }

    // current element kbhi kaam aa skta hai iss liye iss ko stack me push kro
    st.push(nums[i]);
  }

  return res;
}
int main()
{
  vector<int> nums = {4, 1, 2, 5, 3};

  vector<int> result = previousSmallerElement(nums);

  cout << "[ ";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << "]";

  return 0;
}
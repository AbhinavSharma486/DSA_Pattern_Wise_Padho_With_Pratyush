// * Question :- 739. Daily Temperatures
// & Link :- https://leetcode.com/problems/daily-temperatures/description/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temp)
{
  int n = temp.size();

  // res vector create kiya result array store krne ke liye
  // or result array ke last index pr 0 push kr diya hai
  vector<int> res(n);
  res[n - 1] = 0;

  // stack create kiya hai index of greater temperature store krne ke liye
  // stack me array ka last index push kr diya hai
  stack<int> st;
  st.push(n - 1);

  // traverse the array from last to first
  for (int i = n - 2; i >= 0; i--)
  {
    // jab tak stack empty nhi ho jata
    // tab tak stack ke top se vo elements pop kro jo nums[i] se chote/smaller hai
    while (!st.empty() && temp[st.top()] <= temp[i])
    {
      st.pop();
    }

    // agar stack empty hai to result array me 0 store kro
    if (st.empty())
    {
      res[i] = 0;
    }

    // agar else wala block chlega iss ka matlab hai ke
    // stack me jo index store hai uss index pr greater temperature hoga
    // so uss index - current index store kro result array me
    else
    {
      res[i] = st.top() - i;
    }

    // stack me current index push kro
    st.push(i);
  }

  return res;
};
int main()
{
  vector<int> temp = {30, 40, 60, 50};

  vector<int> result = dailyTemperatures(temp);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}
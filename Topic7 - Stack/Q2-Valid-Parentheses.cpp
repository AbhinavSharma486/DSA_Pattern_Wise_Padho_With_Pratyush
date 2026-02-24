// * Question :- 20. Valid Parentheses
// & Link :- https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isValid(string s)
{
  int n = s.size();

  stack<char> st;

  for (int i = 0; i < n; i++)
  {
    // agar s[i] == opening bracket hai to stack me push kro
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
    }

    // agar s[i] == closing brackets hai 100% closing brackets he hai
    else
    {
      if (st.empty())
      {
        return false;
      }

      if (s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[')
      {
        st.pop();
      }
      else
      {
        return false;
      }
    }
  }

  return st.empty();
};
int main()
{
  string s = "([{}]{}([]))()";

  if (isValid(s))
  {
    cout << "Valid Parentheses";
  }
  else
  {
    cout << "Invalid Parentheses";
  }

  return 0;
}
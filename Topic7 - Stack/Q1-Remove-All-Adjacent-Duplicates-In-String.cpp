// * Question :- 1047. Remove All Adjacent Duplicates In String
// & Link :- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
string removeDuplicates(string s)
{
  int n = s.size();

  // stack me chars ko push or pop krne ke liye
  stack<char> st;

  // res string me final result store krenge
  string res;

  // traverse the string
  for (int i = 0; i < n; i++)
  {
    // agar stack empty hai to char push kro
    if (st.empty())
    {
      st.push(s[i]);
      continue;
    }

    // agar stack ka top char or string ka char agar same hai to stack ka char pop kro
    if (st.top() == s[i])
    {
      st.pop();
      continue;
    }

    // iss push ka matlab hai ke stack me char push kro kyuki iss char ka koi bhe adjacent or same pair nhi benga ab
    st.push(s[i]);
  }

  // stack me se char ko pop kro or result string me store kro
  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }

  // jo result string me store hua hai usko reverse kro kyuki stack me reverse order me store hua hai
  reverse(res.begin(), res.end());

  return res;
};

int main()
{
  string s = "abbaca";

  string result = removeDuplicates(s);

  cout << "[";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ", ";
  }
  cout << "]";

  return 0;
}
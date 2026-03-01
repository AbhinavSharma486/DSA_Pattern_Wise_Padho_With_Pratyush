// * Question :- 1209. Remove All Adjacent Duplicates in String II
// &  Link :- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s, int k)
{
  int n = s.size();

  stack<pair<char, int>> st;

  if (k == 1)
  {
    return "";
  }

  // traverse the string
  for (int i = 0; i < n; i++)
  {
    // sbse pehle to char ko select kro or c me store kro
    char c = s[i];

    // agar stack empty hai to character or uska count push kro stack me
    if (st.empty())
    {
      st.push({c, 1});
      continue;
    }

    // check kro ke stack ke top me jo character hai
    // vo or jo new character hai dono agar same nhi hai
    // to new character ko stack vo new char or uska count stack me push kro
    if (st.top().first != c)
    {
      st.push({c, 1});
      continue;
    }

    // check kro ke stack ka top me jo character hai
    // uss ke value given k - 1 se chota hai to
    // sbse pehle to uss char or complete stack se bahar nikal lo
    // then uss ke value increase kro
    // then stack me fir push kr do updated char or uski value ko
    if (st.top().second < (k - 1))
    {
      pair<char, int> p = st.top();
      st.pop();

      st.push({p.first, p.second + 1});
      continue;
    }

    // agar upar ke ek bhe condition nhi chli hai iss ka matlab hai ke
    // stack ke top me jo char hai uss ke value == k - 1 ho gye hai
    // so ab uss ko stack se bahar nikal do
    st.pop();
  }

  // new string create kre hai result store krne ke liye or return krne ke liye
  string res = "";

  // jab tak stack empty nhi ho jata hai tab tak
  // stack ke top se vo elements pop kro
  // jo ab bache hue hai
  while (!st.empty())
  {
    pair<char, int> p = st.top();
    st.pop();

    // jab tak p.second 0 nhi ho jata hai tab tak
    // result string me p.first push krte rho
    while (p.second--)
    {
      res.push_back(p.first);
    }
  }

  reverse(res.begin(), res.end());

  return res;
};

int main()
{
  string s = "deeedbbcccbdaa";
  int k = 3;

  string result = removeDuplicates(s, k);

  cout << "[" << result << "]";

  return 0;
}
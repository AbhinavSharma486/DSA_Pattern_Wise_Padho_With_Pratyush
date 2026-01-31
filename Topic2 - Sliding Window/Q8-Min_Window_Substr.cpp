// * Question :- 76. Minimum Window Substring
// & Link :- https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// yeh function hume btayega ki needed me jo chars ke freq. hai vo have ki curr. window me jo chars hai unki freq. ke equal hai ya nhi
bool sahi(vector<int> &have, vector<int> &needed)
{
  for (int i = 0; i < 256; i++)
  {
    if (have[i] < needed[i])
    {
      return false;
    }
  }

  return true;
}

string minWindow(string s, string t)
{
  int n = s.size();

  // curr. window ke chrs ke freq.
  vector<int> have(256, 0);

  // t ke har ek char ke freq.
  vector<int> needed(256, 0);

  // string t ke har ek char ke freq. count kro and needed me add kro
  for (char i = 0; i < t.size(); i++)
  {
    needed[t[i]]++;
  }

  int low = 0;
  int high = 0;
  int res = INT_MAX;
  int start = 0;

  for (high = 0; high < n; high++)
  {
    // curr. char ko window me include kro
    have[s[high]]++;

    // jab tak info shi hai -> window ko shrink krne ke koshish kro
    while (sahi(have, needed))
    {
      // curr. window ke length calculate kro
      int len = high - low + 1;

      // agar res ke value bada hai to update kro
      if (res > len)
      {
        res = len;

        // low poitner ka index start me store kro
        start = low;
      }

      // left pointer ka char. remove kro / freq. dec. kro
      have[s[low]]--;

      // shrink the window
      low++;
    }
  }

  if (res == INT_MAX)
  {
    return "";
  }

  // start -> starting index of min. window & res -> min. window size
  return s.substr(start, res);
};

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";

  string result = minWindow(s, t);

  cout << "Minimum window substring: " << result << endl;

  return 0;
}
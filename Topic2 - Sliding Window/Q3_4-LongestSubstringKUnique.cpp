// * Question :- Longest Substring with k uniques
// & Link :- https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

int longestKSubstr(string &s, int k)
{
  int n = s.size();

  int low = 0, high = 0;

  // answer store
  int res = INT_MIN;

  // unordered hash map
  unordered_map<char, int> f;

  // sliding window start
  for (high = 0; high < n; high++)
  {
    // current chr ko map me add kro agar pehle se hai to uski freq. increase kro
    f[s[high]]++;

    // jab tak window me k se zyada unique char hai
    // tab tak window ko shrink kro
    while (f.size() > k) // shrink
    {
      // low pointer wale chr ko remove kr do / uss ke freq. kam kr do
      f[s[low]]--;

      // jiss character ki frequency 0 hojati hai usko remove kro
      if (f[s[low]] == 0)
      {
        // uss chr ko hashmap se remove kro
        f.erase(s[low]);
      }

      // low pointer ko aage badhao
      low++;
    }

    // agar window me exactly k distinct chrs hai
    if (f.size() == k)
    {
      // current window ka length calculate kro
      int len = high - low + 1;

      // maximum len ko updare kro
      res = max(res, len);
    }
  }

  // agar ek bhe valid substring nhi hai to -1 return kro
  if (res == INT_MIN)
  {
    return -1;
  }

  return res;
}
int main()
{
  string s = "aabacbebebe";
  int k = 3;

  int result = longestKSubstr(s, k);

  cout << "The longest substring with exactly " << k << " distinct chars is : " << result;

  return 0;
}





// * Question :- 904. Fruit Into Baskets
// & Link :- https://leetcode.com/problems/fruit-into-baskets/description/

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int> &fruits)
{
  int n = fruits.size();

  int low = 0, high = 0;
  int res = INT_MIN;
  unordered_map<int, int> f;

  for (high = 0; high < n; high++)
  {
    f[fruits[high]]++; // current char ko map me add kro / freq. inc. kro

    while (f.size() > 2) // shrink window
    {
      f[fruits[low]]--; // low pointer char ke freq. dec. kro

      if (f[fruits[low]] == 0) // jis char ki freq. 0 ho jati hai uss ko remove kro hashmap se
      {
        f.erase(fruits[low]); // remove kro
      }

      low++; // slide window
    }

    if (f.size() <= 2)
    {
      int len = high - low + 1;

      res = max(res, len);
    }
  }

  return res;
}
int main()
{
  vector<int> fruits = {0, 1, 2, 2};

  int result = totalFruit(fruits);

  cout << "We can pick from all " << result << " trees.";

  return 0;
}






// * Question :- 3. Longest Substring Without Repeating Characters
// & Link :- https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string &s)
{
  int n = s.size();

  int low = 0;
  int high = 0;
  int res = INT_MIN;

  unordered_map<char, int> f;

  for (high = 0; high < n; high++)
  {
    f[s[high]]++; // current char ko map me add kro / freq. inc. kro

    int k = high - low + 1;

    while (f.size() < k) // shrink window
    {
      f[s[low]]--; // low pointer char ke freq. dec. kro

      if (f[s[low]] == 0) // agar low pointer char ki freq. 0 ho jati hai usko remove kro
      {
        f.erase(s[low]); // removing it
      }

      low++; // slide window

      k = high - low + 1;
    }

    if (f.size() == k)
    {
      int len = high - low + 1;

      res = max(res, len);
    }
  }

  return res;
}
int main()
{
  string s = "abcabcbb";

  int result = lengthOfLongestSubstring(s);

  cout << "The longest substring without repeating chars is : " << result;

  return 0;
}

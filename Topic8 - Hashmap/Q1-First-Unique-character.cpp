// * Question :- 387. First Unique Character in a String
// & Link :- https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int firstUniqChar(string s)
{
  int n = s.size();

  unordered_map<char, int> f;

  // sbse pehle sare char ke freq. hashmap me store krenge
  for (int i = 0; i < n; i++)
  {
    f[s[i]]++;
  }

  // then ab ek ek krke har ek index pr traverse krenge
  // or hashmap se puchenge ki konse char ke freq. 1 hai
  for (int i = 0; i < n; i++)
  {
    if (f[s[i]] == 1)
    {
      return i;
    }
  }

  return -1;
};
int main()
{
  string s = "loveleetcode";

  int result = firstUniqChar(s);

  cout << "The first unique character at index is : " << result;

  return 0;
}
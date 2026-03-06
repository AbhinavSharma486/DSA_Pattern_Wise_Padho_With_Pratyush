// * Question :- 409. Longest Palindrome
// & Link :- https://leetcode.com/problems/longest-palindrome/description/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int longestPalindrome(string s)
{
  int n = s.size();

  unordered_map<char, int> f;

  // sbse pehle sare char ke freq. hashmap me store krenge
  for (int i = 0; i < n; i++)
  {
    f[s[i]]++;
  }

  int res = 0;
  bool odd = false;

  // ab hm hashmap me traverse krenge
  for (auto i : f)
  {
    // val me char ke freq. store ho gye hai
    int val = i.second;

    // jb hm val ke mode 2 krenge or 0 aayega to res me val store krenge
    if (val % 2 == 0)
    {
      res = res + val;
    }

    // agar if block nhi chla iss ka matlab hai ke
    // odd freq. present hai hashmap me
    // too odd ko true kr diya hai
    else
    {
      odd = true;
    }
  }

  // agar odd false hai to direct res ko return kr denge
  if (odd == false)
  {
    return res;
  }

  // agar odd true hai too res ko odd ke according update kro
  // ab hm hashmap ko again traverse krenge or vo freq. dekhenge
  // jinke value odd hai
  for (auto i : f)
  {
    // ab val me freq. store kre hai
    int val = i.second;

    // agar val ka mod krne pr result 1 aata hai to
    // res me val ko add krege or - 1 kr denge
    if (val % 2 == 1)
    {
      res = res + val - 1;
    }
  }

  // res me 1 add iss liye kiya hai kyuki
  // maan lo agar bohot sare odd freq. hai and hme mod kr ke result me pair add kr diye hai
  // and kuch letters aise hai jinke freq. 1 hai or bohot sare hai
  // so unn letters me se koi ek latter he baad me add krenge jo ke
  // hm mante hai ke vo hm string ke mid me add krenge so
  // iss liye res me 1 add kiya hai last me
  return res + 1;
};
int main()
{
  string s = "abccccdd";

  int result = longestPalindrome(s);

  cout << "The longest substring with repeating chars is : " << result;

  return 0;
}
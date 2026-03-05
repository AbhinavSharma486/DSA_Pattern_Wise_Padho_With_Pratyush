// * Question :- 1189. Maximum Number of Balloons
// & Link :- https://leetcode.com/problems/maximum-number-of-balloons/description/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
int maxNumberOfBalloons(string s)
{
  int n = s.size();

  unordered_map<char, int> have, need;

  // s me jitne bhe char diye hue thee
  // vo sare have hashmap me store kr diya hai
  for (int i = 0; i < n; i++)
  {
    have[s[i]]++;
  }

  // need me balloon ke char ke freq. set kr de hai
  need['b'] = 1;
  need['a'] = 1;
  need['l'] = 2;
  need['o'] = 2;
  need['n'] = 1;

  int res = INT_MAX;

  // need hashmap pr traverse krenge
  for (auto i : need)
  {
    // char c me need ka char store ho gya hai
    char c = i.first;

    // freq_need me need ke char ke freq. store ho gye hai
    int freq_need = i.second;

    // freq_have me have ke char ke freq. store ho gye hai
    int freq_have = have[c];

    // time me freq_have ko divide krenge freq_need se
    int times = freq_have / freq_need;

    // res me minimum of res or times ko store krenge
    res = min(res, times);
  }

  return res;
};
int main()
{
  string s = "loonbalxballpoon";

  int result = maxNumberOfBalloons(s);

  cout << "The maximum number of balloons is : " << result;

  return 0;
}
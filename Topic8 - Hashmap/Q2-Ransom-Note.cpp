// * Question :- 383. Ransom Note
// & Link :- https://leetcode.com/problems/ransom-note/description/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
bool canConstruct(string ransomNote, string magazine)
{
  unordered_map<char, int> have, need;

  // ransomNote me jitne bhe char diye hue thee
  // un sb ke freq. need hashmap me store kr de hai
  for (int i = 0; i < ransomNote.size(); i++)
  {
    need[ransomNote[i]]++;
  }

  // magazine me jitne bhe char diye hue thee
  // un sb ke freq. have me store kr de hai
  for (int i = 0; i < magazine.size(); i++)
  {
    have[magazine[i]]++;
  }

  // ab check krenge ke need ke char ke freq. have me same hai ya nhi
  // agar same hai too true return krenge
  // agar same nhi hai to false return krenge
  for (auto i : need)
  {
    // char c me need ka char store ho gya hai
    char c = i.first;

    // freq_need me need ka freq. store ho gya hai
    int freq_need = i.second;

    // freq_have me have ka freq. store ho gya hai
    int freq_have = have[c];

    // agar have me char ke freq. km hai to false return krenge
    if (freq_have < freq_need)
    {
      return false;
    }
  }

  return true;
}
int main()
{
  string ransomNote = "aa";
  string magazine = "aab";

  if (canConstruct)
  {
    cout << "True";
  }
  else
  {
    cout << "False";
  }

  return 0;
}
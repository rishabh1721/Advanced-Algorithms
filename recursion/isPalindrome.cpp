#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  bool helper(const string &s, int l, int r)
  {
    if (l >= r)
      return true;
    if (s[l] != s[r])
      return false;
    return helper(s, l + 1, r - 1);
  }

  bool isPalindrome(string s)
  {
    return helper(s, 0, (int)s.size() - 1);
  }
};

int main()
{
  Solution sol;

  string s;
  cout << "Enter string: ";
  cin >> s;

  if (sol.isPalindrome(s))
    cout << "Palindrome\n";
  else
    cout << "Not Palindrome\n";

  return 0;
}

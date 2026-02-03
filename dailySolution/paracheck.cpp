#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
  bool isBalanced(string &s)
  {
    // code here
    stack<char> st;

    for (char c : s)
    {
      // Opening brackets
      if (c == '(' || c == '{' || c == '[')
      {
        st.push(c);
      }
      // Closing brackets
      else
      {
        if (st.empty())
          return false;

        char top = st.top();
        st.pop();

        if ((c == ')' && top != '(') ||
            (c == '}' && top != '{') ||
            (c == ']' && top != '['))
        {
          return false;
        }
      }
    }
    return st.empty();
  }
};

int main()
{
  Solution solution;
  string s = "{[()]}";
  if (solution.isBalanced(s))
    cout << "The string is balanced." << endl;
  else
    cout << "The string is not balanced." << endl;

  return 0;
}
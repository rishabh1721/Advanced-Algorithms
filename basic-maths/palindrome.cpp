#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "enter digit" << endl;
  cin >> n;
  int rev = 0;
  int original = n;
  while (n > 0)
  {
    int digit = n % 10;
    rev = rev * 10 + digit;
    n = n / 10;
  }
  if (rev == original)
  {
    cout << "palindrome number" << endl;
  }
  else
  {
    cout << "not a palindrome number" << endl;
  }
}

// // class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0 || (x % 10 == 0 && x != 0)) return false;

//         int rev = 0;
//         while (x > rev) {
//             rev = rev * 10 + x % 10;
//             x /= 10;
//         }

//         return x == rev || x == rev / 10;
//     }
// };

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
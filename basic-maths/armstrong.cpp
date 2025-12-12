#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "enter" << endl;
  cin >> n;
  int org = n;
  int sum = 0;
  while (n > 0)
  {
    int digit = n % 10;
    sum = sum + digit * digit * digit;
    n = n / 10;
  }
  if (sum == org)
  {
    cout << "armstrong number" << endl;
  }
  else
  {
    cout << "not an armstrong number" << endl;
  }
}
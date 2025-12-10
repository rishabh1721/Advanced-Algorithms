#include <iostream>
using namespace std;

void print10(int n)
{

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = n; j > i; j--)
    {
      cout << "* ";
    }
    cout << endl;
  }
}
int main()
{
  int n;
  cin >> n;
  print10(n);
  return 0;
}
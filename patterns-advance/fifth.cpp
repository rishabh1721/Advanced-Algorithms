#include <iostream>
using namespace std;

void print5(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 5; j >= i; j--)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

int main()

{
  int n;
  cout << "Enter number of rows: ";
  cin >> n;
  print5(n);
  return 0;
}
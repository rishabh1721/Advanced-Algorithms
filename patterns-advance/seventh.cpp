#include <iostream>
using namespace std;

void print7(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++)
    {
      cout << "*";
    }
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    cout << endl;
  }
}

int main()

{
  int n;
  cout << "Enter number of rows: ";
  cin >> n;
  print7(n);
  return 0;
}
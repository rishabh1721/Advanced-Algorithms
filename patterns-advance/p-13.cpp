#include <iostream>
using namespace std;

void print13(int n)
{
  char ch = 'A';
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << ch << " ";

      ch++;
    }
    cout << endl;
  }
}

int main()

{
  int n;
  cout << "Enter number of rows: ";
  cin >> n;
  print13(n);
  return 0;
}
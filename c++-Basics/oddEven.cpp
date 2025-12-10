#include <iostream>
using namespace std;
int main()
{
  // int n;
  // cout << "Enter a number ";
  // cin >> n;
  // if (n % 2 == 0)
  // {
  //   cout << "The number is even";
  // }
  // else
  // {
  //   cout << "The number is odd";
  // }
  // return 0;

  // for (int i = 15; i <= 150; i = i + 15)
  // {

  //   cout << i << endl;
  // }

  int n, p, i;
  cout << "Enter a number ";
  cin >> n;
  cout << "Enter the power ";
  cin >> p;
  int num = n;
  for (i = 1; i < p; i++)
  {
    n = n * num;
  }
  cout << n << endl;

  return 0;
}

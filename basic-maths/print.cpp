#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "enter digit" << endl;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cout << i << endl;
    }
  }
}
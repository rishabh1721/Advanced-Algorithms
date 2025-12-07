#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a = 0, b = 1, c;
  cout << a << endl;
  cout << b << endl;

  for (int i = 2; i < n; i++)
  {
    c = a + b;
    cout << c << endl;
    a = b;
    b = c;

    int ans = INT16_MAX;
  }
  return 0;
}

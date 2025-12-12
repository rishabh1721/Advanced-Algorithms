#include <iostream>
using namespace std;
int main()
{
  int n;
  int count = 0;
  cout << "enter digit" << endl;
  cin >> n;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      count++;
      if ((n / i) != i)
      {
        count++;
      }
    }
    if (count > 2)
    {
      cout << "not prime" << endl;
      ;
    }
    else
    {
      cout << "prime" << endl;
    }
  }
}
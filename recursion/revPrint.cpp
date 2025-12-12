#include <iostream>
using namespace std;
void printRev(int i, int n)
{
  if (i < 1)
  {
    return;
  }

  cout << i << endl;
  printRev(i - 1, n);
}
int main()
{
  printRev(10, 1);
}
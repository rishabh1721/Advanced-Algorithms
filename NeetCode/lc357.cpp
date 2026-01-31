class Solution
{
public:
  int countNumbersWithUniqueDigits(int n)
  {
    if (n == 0)
      return 1;
    int answer = 10;
    int unique = 9;
    int avail = 9;
    for (int i = 2; i <= n && avail > 0; i++)
    {
      unique *= avail;
      answer += unique;
      avail--;
    }
    return answer;
  }
};
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
  {
    val = 0;
    next = NULL;
  }
  ListNode(int data1)
  {
    val = data1;
    next = NULL;
  }
  ListNode(int data1, ListNode *next1)
  {
    val = data1;
    next = next1;
  }
};

class Solution
{
public:
  int findLengthOfLoop(ListNode *head)
  {
    ListNode *temp = head;
    unordered_map<ListNode *, int> mpp;
    int timer = 0;
    while (temp != nullptr)
    {
      if (mpp.find(temp) != mpp.end())
      {
        int lenn = timer - mpp[temp];
        return lenn;
      }
      mpp[temp] = timer;
      temp = temp->next;
      timer++;
    }
    return 0;
  }
};
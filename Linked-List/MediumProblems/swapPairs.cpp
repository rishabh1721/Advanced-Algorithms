
#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }

} *head;

class Solution
{
public:
  Node *pairWiseSwap(Node *head)
  {
    // The task is to complete this method
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *prev = dummy;
    while (prev->next != nullptr && prev->next->next)
    {
      Node *first = prev->next;
      Node *second = first->next;
      first->next = second->next;
      second->next = first;
      prev->next = second;
      prev = first;
    }
    return dummy->next;
  }
};
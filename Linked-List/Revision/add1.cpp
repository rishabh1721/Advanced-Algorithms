#include <iostream>
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
private:
  ListNode *reverse(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp != nullptr)
    {
      ListNode *front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }

public:
  ListNode *addOne(ListNode *head)
  {
    head = reverse(head);
    ListNode *temp = head;
    int carry = 1;
    while (temp != nullptr)
    {
      temp->val += carry;
      if (temp->val < 10)
      {
        carry = 0;
        break;
      }
      else
      {
        temp->val = 0;
        carry = 1;
      }
      temp = temp->next;
    }
    if (carry == 1)
    {
      ListNode *newHead = new ListNode(1);
      head = reverse(head);
      newHead->next = head;
      return newHead;
    }
    else
    {
      head = reverse(head);
      return head;
    }
  }
};
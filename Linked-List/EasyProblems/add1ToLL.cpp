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
};

class Solution
{
public:
  Node *reversal(Node *head)
  {
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
      Node *front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }
  Node *addOne(Node *head)
  {
    head = reversal(head);
    Node *temp = head;
    int carry = 1;
    Node *last = nullptr;
    while (temp != nullptr)
    {
      temp->data = temp->data + carry;
      if (temp->data < 10)
      {
        carry = 0;
        break;
      }
      temp->data = 0;
      carry = 1;
      last = temp;
      temp = temp->next;
    }
    if (carry == 1)
    {
      last->next = new Node(1);
    }

    head = reversal(head);
    return head;
  }
};
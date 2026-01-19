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
  //   Node* reversal(Node* head){
  //       Node* temp = head;
  //       Node* prev = nullptr;
  //       while(temp!=nullptr){
  //           Node* front = temp->next;
  //           temp->next = prev;
  //           prev = temp;
  //           temp = front;

  //       }
  //     return prev;

  int helper(Node *temp)
  {
    int carry;
    if (temp == nullptr)
    {
      return 1;
    }
    carry = helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
    {
      return 0;
    }
    temp->data = 0;
    return 1;
  }
  Node *addOne(Node *head)
  {
    int carry = helper(head);
    if (carry == 1)
    {
      Node *newHead = new Node(1);
      newHead->next = head;
      return newHead;
    }
    return head;
  }
};
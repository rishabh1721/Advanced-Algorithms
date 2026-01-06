#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data1, Node *next1) : data(data1), next(next1) {}
};

Node *insertAtK(Node *head, int el, int k)
{
  if (head == NULL)
  {
    if (k == 1)
    {
      return new Node(el, nullptr);
    }
    else
    {
      return nullptr;
    }
  }
  if (k == 1)
  {
    return new Node(el, head);
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k - 1)
    {
      Node *x = new Node(el, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}
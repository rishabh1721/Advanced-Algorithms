#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  Node *rotate(Node *head, int k)
  {
    if (head == nullptr || k == 0)
      return head;

    Node *tail = head;
    int len = 1;

    while (tail->next != nullptr)
    {
      tail = tail->next;
      len++;
    }

    k = k % len;
    if (k == 0)
      return head;

    tail->next = head; // make circular

    Node *lastNode = head;
    for (int i = 1; i < k; i++)
    {
      lastNode = lastNode->next;
    }

    head = lastNode->next;
    lastNode->next = nullptr; // break circle

    return head;
  }
};

#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *bottom;

  Node(int x)
  {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

class Solution
{
public:
  Node *merge(Node *a, Node *b)
  {
    Node dummy(-1);
    Node *res = &dummy;

    while (a && b)
    {
      if (a->data < b->data)
      {
        res->bottom = a;
        a = a->bottom;
      }
      else
      {
        res->bottom = b;
        b = b->bottom;
      }
      res = res->bottom;
      res->next = nullptr;
    }

    if (a)
      res->bottom = a;
    if (b)
      res->bottom = b;

    return dummy.bottom;
  }

  Node *flatten(Node *root)
  {
    if (!root || !root->next)
      return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
  }
};

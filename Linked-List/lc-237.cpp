#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    ListNode *temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
  }
};
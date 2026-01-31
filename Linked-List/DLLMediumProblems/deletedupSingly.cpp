struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
      ListNode *nextNode = temp->next;
      while (nextNode != nullptr && nextNode->val == temp->val)
      {
        ListNode *duplicate = nextNode;
        nextNode = nextNode->next;
        delete (duplicate);
      }
      temp->next = nextNode;
      temp = temp->next;
    }
    return head;
  }
};
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
  ListNode *reversal(ListNode *head)
  {
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
  ListNode *kthgroup(ListNode *temp, int k)
  {
    k -= 1;
    while (temp != nullptr && k > 0)
    {
      k--;
      temp = temp->next;
    }
    return temp;
  }
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *nextNode = nullptr;
    while (temp != nullptr)
    {
      ListNode *kthNode = kthgroup(temp, k);
      if (kthNode == nullptr)
      {
        if (prev)
          prev->next = temp;
        break;
      }
      nextNode = kthNode->next;
      kthNode->next = nullptr;
      reversal(temp);
      if (temp == head)
      {
        head = kthNode;
      }
      else
      {
        prev->next = kthNode;
      }
      prev = temp;
      temp = nextNode;
    }
    return head;
  }
};
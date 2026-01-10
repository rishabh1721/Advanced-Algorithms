class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

class Solution
{
public:
  Node *segregate(Node *head)
  {
    // code here
    if (head == nullptr || head->next == nullptr)
      return head;
    Node *dummyZero = new Node(-1);
    Node *dummyOne = new Node(-1);
    Node *dummyTwo = new Node(-1);

    Node *zero = dummyZero;
    Node *one = dummyOne;
    Node *two = dummyTwo;

    Node *temp = head;

    while (temp != nullptr)
    {
      if (temp->data == 0)
      {
        zero->next = temp;
        zero = temp;
      }
      else if (temp->data == 1)
      {
        one->next = temp;
        one = temp;
      }
      else
      {
        two->next = temp;
        two = temp;
      }
      temp = temp->next;
    }
    zero->next = (dummyOne->next) ? dummyOne->next : dummyTwo->next;
    one->next = dummyTwo->next;
    two->next = nullptr;
    Node *newHead = dummyZero->next;
    delete (dummyZero);
    delete (dummyOne);
    delete (dummyTwo);
    return newHead;
  }
};
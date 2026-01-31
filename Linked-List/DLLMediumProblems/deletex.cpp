struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

class Solution
{
public:
  void deleteAllOccurOfX(struct Node **head, int x)
  {
    Node *temp = *head;
    Node *nextNode = nullptr;
    Node *prevNode = nullptr;

    while (temp != nullptr)
    {
      if (temp->data == x)
      {

        nextNode = temp->next;
        prevNode = temp->prev;

        // deleting head node
        if (temp == *head)
        {
          *head = nextNode;
          if (*head != nullptr)
            (*head)->prev = nullptr;
        }
        else
        {
          if (prevNode)
            prevNode->next = nextNode;
          if (nextNode)
            nextNode->prev = prevNode;
        }

        delete temp;
        temp = nextNode;
      }
      else
      {
        temp = temp->next;
      }
    }
  }
};

#include <vector>
#include <set>
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
  struct Node *makeUnion(struct Node *head1, struct Node *head2)
  {
    // Set automatically handles duplicates and sorting
    set<int> st;

    // Insert all elements from first list
    Node *curr = head1;
    while (curr != NULL)
    {
      st.insert(curr->data);
      curr = curr->next;
    }

    // Insert all elements from second list
    curr = head2;
    while (curr != NULL)
    {
      st.insert(curr->data);
      curr = curr->next;
    }

    // Create result linked list from sorted set
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    for (int val : st)
    {
      tail->next = new Node(val);
      tail = tail->next;
    }

    return dummy->next;
  }
};

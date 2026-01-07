#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *back;

  Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
      : data(data1), next(next1), back(back1) {}
};

Node *convertArrToDLL(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *curr = new Node(arr[i]);
    prev->next = curr;
    curr->back = prev;
    prev = curr;
  }
  return head;
}

Node *deleteKthElement(Node *head, int k)
{
  if (head == nullptr || k <= 0)
    return head;

  Node *temp = head;
  int cnt = 1;

  while (temp != nullptr && cnt < k)
  {
    temp = temp->next;
    cnt++;
  }

  if (temp == nullptr)
    return head; // k > length

  Node *prev = temp->back;
  Node *next = temp->next;

  // delete head
  if (prev == nullptr)
  {
    head = next;
    if (head)
      head->back = nullptr;
  }
  // delete tail
  else if (next == nullptr)
  {
    prev->next = nullptr;
  }
  // delete middle
  else
  {
    prev->next = next;
    next->back = prev;
  }

  delete temp;
  return head;
}

void print(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {2, 3, 5, 8};
  Node *head = convertArrToDLL(arr);

  head = deleteKthElement(head, 3); // delete 3rd element (5)
  print(head);

  return 0;
}

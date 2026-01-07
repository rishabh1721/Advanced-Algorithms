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

void print(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *insertTail(Node *head, int X)
{
  if (head == nullptr)
  {
    return new Node(X);
  }

  // Single node list
  if (head->next == nullptr)
  {
    Node *newNode = new Node(X);
    newNode->next = head;
    head->back = newNode;
    return newNode;
  }

  // Reach tail
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }

  // Insert before tail
  Node *prev = tail->back;
  Node *newNode = new Node(X);

  newNode->next = tail;
  newNode->back = prev;
  prev->next = newNode;
  tail->back = newNode;

  return head;
}

int main()
{
  vector<int> arr = {2, 3, 5, 8};
  Node *head = convertArrToDLL(arr);

  head = insertTail(head, 5); // delete 3rd element (5)
  print(head);

  return 0;
}
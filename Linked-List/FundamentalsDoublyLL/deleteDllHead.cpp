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
}

Node *deleteHead(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return nullptr;
  }
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;
  delete prev;
  return head;
}

int main()
{
  vector<int> arr = {2, 3, 5, 8};
  Node *head = convertArrToDLL(arr);
  head = deleteHead(head);
  print(head);
  return 0;
}

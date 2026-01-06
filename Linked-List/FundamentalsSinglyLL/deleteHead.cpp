#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data1, Node *next1) : data(data1), next(next1) {}
};

Node *convertArr2LL(vector<int> &arr)
{
  if (arr.size() == 0)
    return nullptr;

  Node *head = new Node(arr[0], nullptr);
  Node *mover = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

Node *removesHead(Node *head)
{
  if (head == nullptr)
    return head;
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

int main()
{
  vector<int> arr = {2, 5, 8, 7};

  Node *head = convertArr2LL(arr);

  // print linked list
  Node *cur = head;
  while (cur != nullptr)
  {
    cout << cur->data << " ";
    cur = cur->next;
  }
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  head = removesHead(head);
}

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

void deleteNode(Node *temp)
{
  Node *prev = temp->back;
  Node *front = temp->next;
  if (front == nullptr)
  {
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }
  prev->next = front;
  front->back = prev;
  temp->next = temp->back = nullptr;
  free(temp);
}

int main()
{
  vector<int> arr = {2, 3, 5, 8};
  Node *head = convertArrToDLL(arr);

  deleteNode(head->next); // delete 3rd element (5)
  print(head);

  return 0;
}
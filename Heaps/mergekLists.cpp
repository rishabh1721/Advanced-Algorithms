#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        struct compare{
            bool operator()(Node* a, Node* b){
                return a->data > b->data;
            }
        };
        priority_queue<Node*,vector<Node*>,compare> pq;
        for(auto node: arr){
            if(node) pq.push(node);
        }
        Node dummy(0);
        Node* tail = &dummy;
        while(!pq.empty()){
            Node* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next)pq.push(smallest->next);
        }
        return dummy.next;
    }
};
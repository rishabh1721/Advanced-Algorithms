#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = nullptr;
        Node* suc = nullptr;

        Node* curr = root;

        // predecessor
        while(curr) {
            if(curr->data < key) {
                pre = curr;
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        curr = root;

        // successor
        while(curr) {
            if(curr->data > key) {
                suc = curr;
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};
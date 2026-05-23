#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
         while(root != nullptr && root->data != key){
            root = key < root->data ? root->left:root->right;
        }
        return root != nullptr;
    }
};
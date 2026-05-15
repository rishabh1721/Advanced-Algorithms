#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    bool isSymmetric(Node* root) {
        // code here
        if(root==nullptr) return true;
        return isSym(root->left, root->right);
    }
    bool isSym(Node* left, Node* right){
        if(left == nullptr || right==nullptr){
            return left== right;
        }
        if(left->data != right->data) return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
        
        
    } 
};
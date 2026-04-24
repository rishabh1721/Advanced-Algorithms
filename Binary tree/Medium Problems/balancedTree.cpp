#include <iostream>
#include <cmath>
using namespace std;
class Node {
  public:
    int data;
    Node* left;//
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};//


class Solution {
  public:
    bool isBalanced(Node* root) {
        // code here
        return dfsH(root) != -1;
        
    }
    int dfsH(Node* root){
        if(root == nullptr) return 0;
        int lh = dfsH(root->left);
        if(lh==-1) return -1;
        int rh = dfsH(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return max(lh,rh) + 1;
    }
};
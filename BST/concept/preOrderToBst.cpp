#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

class Solution {
  public:
  Node* build(vector<int>&pre, int& i,long long bound){
        if(pre.size() == i || pre[i] > bound) return nullptr;
        Node* root = new Node(pre[i++]);
        root->left = build(pre,i,root->data);
        root->right = build(pre,i,bound);
        return root;
    }

    Node* preToBST(vector<int>& pre) {
        // code here
        int i=0;
        return build(pre,i,LLONG_MAX);
    }
    
};
#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> res;
        recur(root,0,res);
        return res;
    }
    void recur(Node* node, int level, vector<int>& res){
        if(node==nullptr) return;
        if(level == res.size()) res.push_back(node->data);
        recur(node->left,level+1,res);
        recur(node->right,level+1,res);
        

    }
};
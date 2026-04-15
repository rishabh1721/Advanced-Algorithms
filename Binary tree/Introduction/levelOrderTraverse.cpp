#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        if(root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
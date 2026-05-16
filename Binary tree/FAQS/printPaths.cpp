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
  
    void solve(Node* root, vector<int>& path, vector<vector<int>>& ans) {
        
        if(root == nullptr) return;
        
        // add current node
        path.push_back(root->data);
        
        // leaf node
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }
        
        // left subtree
        solve(root->left, path, ans);
        
        // right subtree
        solve(root->right, path, ans);
        
        // backtrack
        path.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        
        vector<vector<int>> ans;
        vector<int> path;
        
        solve(root, path, ans);
        
        return ans;
    }
};
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    // void inorder(TreeNode* root , vector<int>& arr){
    //      if(root == nullptr) return;
    //     inorder(root->left,arr);
    //     arr.push_back(root->val);
    //     inorder(root->right,arr);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                arr.push_back(node->val);
                node = node->right;
            }
        }
        return arr;
        
    }
};
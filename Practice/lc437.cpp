#include <iostream>
#include <vector>
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
    long long countPath(TreeNode* root, long long targetSum){
        if(!root)return 0;
        long long ans = 0;
        if(root->val == targetSum)ans++;
        ans += countPath(root->left, targetSum - root->val);
        ans += countPath(root->right, targetSum - root->val);
        return ans;

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return countPath(root,targetSum) +  pathSum(root->left, targetSum)+pathSum(root->right, targetSum) ;
    }
};
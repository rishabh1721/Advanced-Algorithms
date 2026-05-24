#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
//
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 class NodeValue{
public:
    int minNode;
    int maxNode;
    int sum;

    NodeValue(int mn,int mx,int sm){
        minNode = mn;
        maxNode = mx;
        sum = sm;
    }
};

class Solution {
public:

    int ans = 0;

    NodeValue solve(TreeNode* root){

        if(!root)
            return NodeValue(INT_MAX,INT_MIN,0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.maxNode < root->val &&
           root->val < right.minNode){

            int currSum =
                left.sum +
                right.sum +
                root->val;

            ans = max(ans,currSum);

            return NodeValue(
                min(root->val,left.minNode),
                max(root->val,right.maxNode),
                currSum
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.sum,right.sum)
        );
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};
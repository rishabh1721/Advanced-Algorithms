
struct Node
{
    int data;
    Node* left, * right;
}; 

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int targetSum) {
        // Your code here
        if(root==nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return targetSum == root->data;
        return hasPathSum(root->left, targetSum-root->data) || 
        hasPathSum(root->right, targetSum-root->data);
    }
};
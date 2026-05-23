class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  Node* findLastChild(Node* root){
      if(root->right == nullptr) return root;
      return findLastChild(root->right);
  }
  Node* helper(Node* root){
      if(root->left == nullptr) return root->right;
      if(root->right == nullptr) return root->left;
      Node* rightChild = root->right;
      Node* lastChild = findLastChild(root->left);
      lastChild->right = rightChild;
      return root->left;
  }
    Node* delNode(Node* root, int x) {
        // code here
        if(root == nullptr) return nullptr;
        if(root->data == x){
            return helper(root);
        }
        Node* dummy = root;
        while(root){
            if(root->data > x){
                if(root->left != nullptr && root->left->data == x){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != nullptr && root->right->data == x){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
            
        }
        return dummy;
    }
};
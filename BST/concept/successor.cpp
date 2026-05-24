
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
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        Node* ans = nullptr;
        while(root != nullptr){
            if(k->data >= root->data){
                root = root->right;
            }
            else{
                ans= root;
                root = root->left;
            }
        }
        return ans ? ans->data : -1;
    }
};
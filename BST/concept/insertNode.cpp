
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
    Node* insert(Node* root, int key) {
        // code  here
         if(root == nullptr) return new Node(key);
        Node* curr = root;
        while(true){
            if(curr->data <= key){
                if(curr->right != nullptr) curr = curr->right;
                else{
                    curr->right = new Node(key);
                    break;
                }
            }
                else{
                    if(curr->left != nullptr) curr = curr->left;
                    else{
                        curr->left = new Node(key);
                        break;
                    }

                
            }
        }
        return root;
    }
};
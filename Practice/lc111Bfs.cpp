#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 
class Solution {
  public:
    int minDepth(Node *root) {
        // code here
        if(root == nullptr) return 0;
        queue<Node*>q;
        q.push(root);
        int depth = 1;
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr) return depth;
                if(node->left) q.push(node->left);
                
                if(node->right) q.push(node->right);
                
               
            }
             depth++;
           
        }
         return depth;
    }
};
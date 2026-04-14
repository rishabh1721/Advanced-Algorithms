#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        
        stack<Node*> st;
        st.push(root);
        while(st.empty() == false){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);
            if(node->right != nullptr){
                st.push(node->right);
            }
            if(node->left != nullptr){
                st.push(node->left);
            }
        }
        return ans;
        
            
        
    }
};
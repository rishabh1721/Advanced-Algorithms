#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
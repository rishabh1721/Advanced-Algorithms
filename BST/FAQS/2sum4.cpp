#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BSTIterator{
    stack<Node*> st;
    bool reverse = true;
    public:
    BSTIterator(Node* root, bool isRev){
        reverse = isRev;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }

    private:
     void pushAll(Node* root){
        for(; root != nullptr ;){
            st.push(root);
            if(reverse != true){
                root = root->left;
            }else root = root->right;
        }
     }
};

class Solution {
  public:
    bool findTarget(Node *root, int k) {
        // your code here.
         if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i+j==k)return true;
            else if(i+j < k)i=l.next();
            else j= r.next();
        }
        return false;
    }
};
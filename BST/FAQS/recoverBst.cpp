#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    private:
            Node* prev;
            Node* first;
            Node* mid;
            Node* last;
    private: 
            void inorder(Node* root){
                if(root==nullptr)return;
                inorder(root->left);
                if(prev!=NULL && (root->data < prev->data)){
                    if(first == nullptr){
                        first = prev;
                        mid = root;
                    }
                    else{
                        last = root;
                    }
                }
                prev = root;
                inorder(root->right);
            }
  public:
    void correctBST(Node* root) {
        // add code here.
        first=last=mid=nullptr;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data , last->data);
        else if(first && mid) swap(first->data,mid->data);
    }
};
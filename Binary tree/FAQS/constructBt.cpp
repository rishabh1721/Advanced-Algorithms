#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
public:

    Node* solve(vector<int>& inorder,
                vector<int>& preorder,
                int inStart,
                int inEnd,
                int& preIndex,
                unordered_map<int,int>& mp) {

        if (inStart > inEnd)
            return NULL;

        Node* root = new Node(preorder[preIndex++]);

        int pos = mp[root->data];

        root->left = solve(inorder, preorder,
                           inStart, pos - 1,
                           preIndex, mp);

        root->right = solve(inorder, preorder,
                            pos + 1, inEnd,
                            preIndex, mp);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {

        unordered_map<int,int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return solve(inorder,
                     preorder,
                     0,
                     inorder.size() - 1,
                     preIndex,
                     mp);
    }
};
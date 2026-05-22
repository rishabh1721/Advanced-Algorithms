#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};


class Solution {
public:

    Node* build(vector<int>& inorder,
                    int is,
                    int ie,
                    vector<int>& postorder,
                    int ps,
                    int pe,
                    map<int,int>& hm) {

        if (ps > pe || is > ie)
            return nullptr;

        Node* root = new Node(postorder[pe]);

        int inRoot = hm[root->data];

        int numsL = inRoot - is;

        root->left = build(inorder,
                           is,
                           inRoot - 1,
                           postorder,
                           ps,
                           ps + numsL - 1,
                           hm);

        root->right = build(inorder,
                            inRoot + 1,
                            ie,
                            postorder,
                            ps + numsL,
                            pe - 1,
                            hm);

        return root;
    }

    Node* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        map<int,int> hm;

        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        return build(inorder,
                     0,
                     inorder.size() - 1,
                     postorder,
                     0,
                     postorder.size() - 1,
                     hm);
    }
};
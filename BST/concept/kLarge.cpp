#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// return the Kth largest element in the given BST rooted at 'root'
class Solution {
public:
    int solve(Node* root, int& k) {
        if(root == nullptr) return -1;

        int right = solve(root->right, k);
        if(right != -1) return right;

        k--;
        if(k == 0) return root->data;

        return solve(root->left, k);
    }

    int kthLargest(Node* root, int k) {
        return solve(root, k);
    }
};
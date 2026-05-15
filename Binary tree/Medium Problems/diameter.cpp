#include <iostream>
using namespace std;

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
    int diameter(Node* root) {
        // code here
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(Node* node, int& diameter){
        if(!node){
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh,rh);
    }
};
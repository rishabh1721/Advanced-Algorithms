#include <iostream>
#include <climits>
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
    int findMaxSum(Node *root) {
        // code here
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
    int maxPath(Node* node, int& maxi){
        if(!node) return 0;
        int ls = max(0,maxPath(node->left,maxi));
        int rs = max(0,maxPath(node->right,maxi));
        maxi = max(maxi, ls+rs+node->data);
        return max(ls,rs) + node->data;
    }
};
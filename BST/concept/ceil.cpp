#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
    int findCeil(Node* root, int x) {
        // code here
        int ceils = -1;
        while(root){
            if(root->data == x){
                ceils = root->data;
                return ceils;
            }
            if(x > root->data){
                root = root->right;
            }
            else{
                ceils = root->data;
                root = root->left;
            }
        }
        return ceils;
    }
};

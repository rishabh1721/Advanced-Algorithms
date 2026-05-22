#include <iostream>
#include <map>
#include <queue>
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


class Solution {
public:

    int findDist(map<Node*, Node*>& mpp, Node* target) {

        queue<Node*> q;
        q.push(target);

        map<Node*, int> vis;
        vis[target] = 1;

        int maxi = 0;

        while (!q.empty()) {

            int sz = q.size();
            bool flag = false;

            for (int i = 0; i < sz; i++) {

                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    flag = true;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    flag = true;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if (mpp[node] && !vis[mpp[node]]) {
                    flag = true;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }

            if (flag) maxi++;
        }

        return maxi;
    }

    Node* bfsToMarkParent(Node* root,
                          map<Node*, Node*>& mpp,
                          int target) {

        queue<Node*> q;
        q.push(root);

        Node* res = NULL;

        while (!q.empty()) {

            Node* node = q.front();
            q.pop();

            if (node->data == target)
                res = node;

            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int minTime(Node* root, int target) {

        map<Node*, Node*> mpp;

        Node* targetNode =
            bfsToMarkParent(root, mpp, target);

        return findDist(mpp, targetNode);
    }
};
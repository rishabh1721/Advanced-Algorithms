
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};


class Solution {

  public:

    void markParent(Node* root,
                    unordered_map<Node*, Node*>& parent) {

        queue<Node*> q;

        q.push(root);

        while (!q.empty()) {

            Node* current = q.front();

            q.pop();

            if (current->left) {

                parent[current->left] = current;

                q.push(current->left);
            }

            if (current->right) {

                parent[current->right] = current;

                q.push(current->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {

        if (!root) return NULL;

        if (root->data == target)
            return root;

        Node* left = findTarget(root->left, target);

        if (left) return left;

        return findTarget(root->right, target);
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {

        unordered_map<Node*, Node*> parent;

        markParent(root, parent);

        Node* targetNode = findTarget(root, target);

        queue<Node*> q;

        unordered_map<Node*, bool> visited;

        q.push(targetNode);

        visited[targetNode] = true;

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            if (level++ == k)
                break;

            for (int i = 0; i < size; i++) {

                Node* current = q.front();

                q.pop();

                if (current->left &&
                    !visited[current->left]) {

                    q.push(current->left);

                    visited[current->left] = true;
                }

                if (current->right &&
                    !visited[current->right]) {

                    q.push(current->right);

                    visited[current->right] = true;
                }

                if (parent[current] &&
                    !visited[parent[current]]) {

                    q.push(parent[current]);

                    visited[parent[current]] = true;
                }
            }
        }

        vector<int> result;

        while (!q.empty()) {

            result.push_back(q.front()->data);

            q.pop();
        }

        sort(result.begin(), result.end());

        return result;
    }
};
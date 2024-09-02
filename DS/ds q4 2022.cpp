#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int num) {
        data = num;
        left = NULL;
        right = NULL;
    }
};

class BT {
public:
    Node* root;

    BT() {
        root = NULL;
    }

    int levelorder(Node* temp) {
        if (temp == NULL) {
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* curr;

        while (q.size() > 1) {
            curr = q.front();
            q.pop();

            if (curr == NULL) {
                q.push(NULL);
            }
            else {
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return curr->data;
    }

    int calsum(Node* temp) {
        int total = 0;
        if (temp == NULL) {
            return total;
        }
        else {
            total += levelorder(temp);
        }
        return total;
    }

    void calc(Node* temp, int k) {
        if (temp == NULL) {
            return;
        }
        else {
            if (calsum(temp) == k) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
};

int main() {
    BT b;
    b.root = new Node(1);
    b.root->left = new Node(3);
    b.root->right = new Node(-1);
    b.root->left->left = new Node(2);
    b.root->left->right = new Node(1);
    b.root->left->right->right = new Node(1);
    b.root->right->left = new Node(4);
    b.root->right->right = new Node(5);
    b.root->right->left->left = new Node(1);
    b.root->right->left->right = new Node(2);
    b.root->right->right->right = new Node(6);

    b.levelorder(b.root);
    b.calc(b.root, 5);

    return 0;
}

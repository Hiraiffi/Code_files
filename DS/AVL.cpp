#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node* right;
    Node* left;

    Node()
    {
        data = 0;
        right = NULL;
        left = NULL;
        height = 1;
    }
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
        height = 1;
    }
};
class AVL
{
public:
    Node* root;
    AVL()
    {
        root = NULL;
    }
    int Height(Node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        return temp->height;
    }
    int getBalance(Node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            return Height(temp->left) - Height(temp->right);
        }
    }
    Node* leftrotate(Node* temp)
    {
        Node* y = temp->right;
        Node* T2 = temp->left;

        temp->right = T2;
        temp->left = y;

        y->height = 1 + max(Height(y->left), Height(y->right));
        temp->height = 1 + max(Height(y->left), Height(y->right));
        return y;
    }
    Node* rightrotate(Node* temp)
    {
        Node* y = temp->left;
        Node* T2 = temp->right;

        temp->left = T2;
        temp->right = y;

        y->height = 1 + max(Height(y->left), Height(y->right));
        temp->height = 1 + max(Height(temp->left), Height(temp->right));

        return y;
    }
    Node* insert(Node* temp, int val)
    {
        if (temp == NULL)
        {
            return new Node(val);
        }
        else if (val < temp->data)
        {
            temp->left = insert(temp->left, val);
        }
        else if (val > temp->data)
        {
            temp->right = insert(temp->right, val);
        }
        else
        {
            return temp;
        }
        temp->height = 1 + max(Height(temp->left), Height(temp->right));
        int balance = getBalance(temp);

        if (balance > 1 && val < temp->left->data)
        {
            return rightrotate(temp);
        }
        if (balance < -1 && val > temp->right->data)
        {
            return leftrotate(temp);
        }
        if (balance > 1 && val > temp->left->data)
        {
            temp->left = leftrotate(temp->left);
            return rightrotate(temp);
        }
        if (balance < -1 && val < temp->right->data)
        {
            temp->right = rightrotate(temp->right);
            return leftrotate(temp);
        }

        return temp;
    }
    bool search(Node* temp, int val)
    {
        if (temp == NULL)
        {
            return false;
        }
        else if (val == temp->data)
        {
            return true;
        }
        else if (val < temp->data)
        {
            bool var = search(temp->left, val);
            return var;
        }
        else
        {
            bool var2 = search(temp->right, val);
            return var2;
        }
    }
    Node* minval(Node* temp)
    {
        Node* n = temp;

        while (n->left != NULL)
        {
            n = n->left;
        }
        return n;
    }
    Node* deleteNode(Node* temp, int val)
    {
        if (temp == NULL)
        {
            return temp;
        }
        else if (val < temp->data)
        {
            temp->left = deleteNode(temp->left, val);
        }
        else if (val > temp->data)
        {
            temp->right = deleteNode(temp->right, val);
        }
        else
        {
            if (temp->left == NULL || temp->right == NULL)
            {
                Node* n = (temp->left) ? temp->left : temp->right;
                if (n == NULL)
                {
                    n = temp;
                    temp = NULL;
                }
                else
                {
                    *temp = *n;
                    delete n;
                }
            }
            else
            {
                Node* n = minval(temp->right);
                temp->data = n->data;
                temp->right = deleteNode(temp->right, n->data);
            }
            if (temp == NULL)
            {
                return temp;
            }
        }

        temp->height = 1 + max(Height(temp->left), Height(temp->right));
        int balance = getBalance(temp);

        if (balance > 1 && getBalance(temp->left) >= 0)
        {
            return rightrotate(temp);
        }
        if (balance < -1 && getBalance(temp->right) <= 0)
        {
            return leftrotate(temp);
        }
        if (balance > 1 && getBalance(temp->left) < 0)
        {
            temp->left = leftrotate(temp->left);
            return rightrotate(temp);
        }
        if (balance < -1 && getBalance(temp->right) > 0)
        {
            temp->right = rightrotate(temp->right);
            return leftrotate(temp);
        }
        return temp;
    }
    void preOrder(Node* temp)
    {
        if (temp == NULL)
        {
            return;
        }
        else
        {
            cout << temp->data << " ";
            preOrder(temp->left);
            preOrder(temp->right);
        }
    }
};

int main()
{
    AVL a;
    a.root = a.insert(a.root, 5);
    a.root = a.insert(a.root, 10);
    a.root = a.insert(a.root, 14);
    a.root = a.deleteNode(a.root, 14);

    cout << "Preorder traversal of the AVL tree after deletion: ";
    a.preOrder(a.root);

    return 0;
}

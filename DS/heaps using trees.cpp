#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MaxHeapTree {
private:
    TreeNode* root;

    void heapifyUp(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        while (node->parent != nullptr && node->data > node->parent->data) {
            std::swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    void heapifyDown(TreeNode* node) {
        while (true) {
            TreeNode* leftChild = node->left;
            TreeNode* rightChild = node->right;
            TreeNode* largest = node;

            if (leftChild != nullptr && leftChild->data > largest->data) {
                largest = leftChild;
            }

            if (rightChild != nullptr && rightChild->data > largest->data) {
                largest = rightChild;
            }

            if (largest != node) {
                std::swap(node->data, largest->data);
                node = largest;
            } else {
                break;
            }
        }
    }

    TreeNode* findLastNode() {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* lastNode = root;
        while (lastNode->left != nullptr) {
            lastNode = lastNode->left;
        }

        return lastNode;
    }

public:
    MaxHeapTree() : root(nullptr) {}

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);

        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode* lastNode = findLastNode();
            newNode->parent = lastNode;
            lastNode->left = newNode;
            heapifyUp(newNode);
        }
    }

    int extractMax() {
        if (root == nullptr) {
            std::cerr << "Error: The heap is empty.\n";
            return -1; // Return a default value; consider using exceptions in a real application.
        }

        int maxVal = root->data;

        TreeNode* lastNode = findLastNode();
        if (lastNode == root) {
            delete root;
            root = nullptr;
        } else {
            std::swap(root->data, lastNode->data);
            if (lastNode->parent->right == lastNode) {
                lastNode->parent->right = nullptr;
            } else {
                lastNode->parent->left = nullptr;
            }
            heapifyDown(root);
            delete lastNode;
        }

        return maxVal;
    }

    void display(TreeNode* node, int level = 0) const {
        if (node != nullptr) {
            display(node->right, level + 1);
            for (int i = 0; i < level; ++i) std::cout << "   ";
            std::cout << node->data << std::endl;
            display(node->left, level + 1);
        }
    }

    void display() const {
        display(root);
    }
};

int main() {
    MaxHeapTree maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(25);
    maxHeap.insert(5);

    std::cout << "Max Heap after insertions:\n";
    maxHeap.display();

    int maxVal = maxHeap.extractMax();
    std::cout << "Extracted Max Value: " << maxVal << std::endl;

    std::cout << "Max Heap after extraction:\n";
    maxHeap.display();

    return 0;
}

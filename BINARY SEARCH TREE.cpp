#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

    bool searchNode(Node* node, int key) {
        if (node == NULL) {
            return false;
        }

        if (key == node->key) {
            return true;
        }
        else if (key < node->key) {
            return searchNode(node->left, key);
        }
        else {
            return searchNode(node->right, key);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    bool search(int key) {
        return searchNode(root, key);
    }
};

int main() {
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << bst.search(7) << endl; // Output: 1 (true)
    cout << bst.search(12) << endl; // Output: 0 (false)

    return 0;
}

#include <iostream>

using namespace std;

// Definindo a estrutura do nó
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para percorrer a árvore em pré-ordem (preorder)
void preorder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    // Criando a raiz da árvore
    Node* root = createNode(1);

    // Criando os nós filhos da raiz
    root->left = createNode(2);
    root->right = createNode(3);

    // Criando os nós filhos do nó esquerdo da raiz
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Percorrendo a árvore em pré-ordem (preorder)
    cout << "Preorder traversal: ";
    preorder(root);

    return 0;
}

#include <iostream>

using namespace std;

// Definindo a estrutura do n�
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fun��o para criar um novo n�
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para percorrer a �rvore em p�s-ordem (postorder)
void postorder(Node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    // Criando a raiz da �rvore
    Node* root = createNode(1);

    // Criando os n�s filhos da raiz
    root->left = createNode(2);
    root->right = createNode(3);

    // Criando os n�s filhos do n� esquerdo da raiz
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Percorrendo a �rvore em p�s-ordem (postorder)
    cout << "Postorder traversal: ";
    postorder(root);

    return 0;
}

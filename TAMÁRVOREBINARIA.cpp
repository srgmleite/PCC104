#include <iostream>

using namespace std;

// Defini��o da estrutura de um n� da �rvore
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

// Fun��o recursiva que calcula o tamanho da �rvore
int getSize(Node* node) {
    if (node == NULL) { // Caso base: n� vazio
        return 0;
    }
    else { // Caso geral: n� n�o vazio
        // Tamanho da �rvore = tamanho da sub�rvore esquerda + tamanho da sub�rvore direita + 1 (raiz)
        return getSize(node->left) + getSize(node->right) + 1;
    }
}

int main() {
    // Cria��o da �rvore bin�ria de exemplo
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // C�lculo do tamanho da �rvore
    int size = getSize(root);

    // Impress�o do resultado
    cout << "Tamanho da arvore: " << size << endl;

    return 0;
}

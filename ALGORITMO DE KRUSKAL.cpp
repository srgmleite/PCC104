#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int primeiro;
    int segundo;
    int peso;
} aresta;

void uniao(int* comp, int n_vertices, int c1, int c2) {
    for (int i = 0; i < n_vertices; i++) {
        if (comp[i] == c2)
            comp[i] = c1;
    }
}

int kruskal(aresta* grafo, int n_arestas, int* comp, int n_vertices, vector<aresta>& caminho) {
    int total = 0;

    for (int i = 0; i < n_arestas; i++) {
        if (comp[grafo[i].primeiro] != comp[grafo[i].segundo]) {
            total += grafo[i].peso;
            caminho.push_back(grafo[i]); // Adiciona a aresta selecionada ao caminho percorrido
            uniao(comp, n_vertices, comp[grafo[i].primeiro], comp[grafo[i].segundo]);
        }
    }

    return total;
}

void exibirCaminho(const vector<aresta>& caminho) {
    cout << "Caminho percorrido:" << endl;
    for (const auto& aresta : caminho) {
        cout << aresta.primeiro << " - " << aresta.segundo << " (Peso: " << aresta.peso << ")" << endl;
    }
}

int main() {
    // Conjunto pré-definido de arestas
    aresta arestas[10] = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 6},
        {1, 4, 3},
        {2, 3, 1},
        {2, 4, 9},
        {3, 4, 5},
        {3, 5, 7},
        {4, 5, 6}
    };

    int componentes[6];

    for (int i = 0; i < 6; i++)
        componentes[i] = i;

    vector<aresta> caminho; // Vetor para armazenar o caminho percorrido

    int custoMST = kruskal(arestas, 10, componentes, 6, caminho);

    cout << "CUSTO DA ÁRVORE MST: " << custoMST << endl;

    exibirCaminho(caminho);

    return 0;
}

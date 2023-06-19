#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int primeiro;
    int segundo;
    int peso;
} aresta;

int encontrarRaiz(int* comp, int vertice) {
    while (comp[vertice] != vertice)
        vertice = comp[vertice];
    return vertice;
}

void uniao(int* comp, int n_vertices, int c1, int c2) {
    int raizC1 = encontrarRaiz(comp, c1);
    int raizC2 = encontrarRaiz(comp, c2);
    comp[raizC2] = raizC1;
}

int kruskal(aresta* grafo, int n_arestas, int* comp, int n_vertices, vector<aresta>& caminho) {
    int total = 0;

    for (int i = 0; i < n_arestas; i++) {
        int raizP = encontrarRaiz(comp, grafo[i].primeiro);
        int raizS = encontrarRaiz(comp, grafo[i].segundo);

        if (raizP != raizS) {
            total += grafo[i].peso;
            caminho.push_back(grafo[i]);
            uniao(comp, n_vertices, raizP, raizS);
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

    vector<aresta> caminho;

    int custoMST = kruskal(arestas, 10, componentes, 6, caminho);

    cout << "CUSTO DA ÁRVORE MST: " << custoMST << endl;

    exibirCaminho(caminho);

    return 0;
}


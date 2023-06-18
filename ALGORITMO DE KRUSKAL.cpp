#include <iostream>
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

int kruskal(aresta* grafo, int n_arestas, int* comp, int n_vertices) {
    int total = 0;

    for (int i = 0; i < n_arestas; i++) {
        if (comp[grafo[i].primeiro] != comp[grafo[i].segundo]) {
            total += grafo[i].peso;
            uniao(comp, n_vertices, comp[grafo[i].primeiro], comp[grafo[i].segundo]);
        }
    }

    return total;
}

int main() {
    aresta arestas[10];
    int componentes[6];

    for (int i = 0; i < 10; i++) {
        cout << "ENTRE COM A ARESTA: " << i << endl;
        cout << "PRIMEIRO: ";
        cin >> arestas[i].primeiro;
        cout << "SEGUNDO: ";
        cin >> arestas[i].segundo;
        cout << "PESO: ";
        cin >> arestas[i].peso;
    }

    for (int i = 0; i < 6; i++)
        componentes[i] = i;

    cout << "CUSTO DA ÁRVORE MST: " << kruskal(arestas, 10, componentes, 6) << endl;

    return 0;
}

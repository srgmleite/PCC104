#include <iostream>
#include <climits>
using namespace std;

typedef struct {
    int primeiro;
    int segundo;
    int peso;
} aresta;

int minKey(int chave[], bool mstSet[], int n_vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n_vertices; v++) {
        if (mstSet[v] == false && chave[v] < min) {
            min = chave[v];
            min_index = v;
        }
    }

    return min_index;
}

int prim(aresta* grafo, int n_arestas, int n_vertices) {
    int chave [n_vertices];
    bool mstSet [n_vertices];

    for (int i = 0; i < n_vertices; i++) {
        chave[i] = INT_MAX;
        mstSet[i] = false;
    }

    chave[0] = 0;

    for (int count = 0; count < n_vertices - 1; count++) {
        int u = minKey(chave, mstSet, n_vertices);
        mstSet[u] = true;

        for (int v = 0; v < n_vertices; v++) {
            if (mstSet[v] == false && grafo[v].peso < chave[v]) {
                chave[v] = grafo[v].peso;
            }
        }
    }

    int total = 0;
    for (int i = 1; i < n_vertices; i++) {
        total += chave[i];
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

    const int n_vertices = 6; // Número de vértices do grafo

    cout << "CUSTO DA ÁRVORE MST: " << prim(arestas, 10, n_vertices) << endl;

    return 0;
}


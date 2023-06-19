#include <iostream>
#include <climits>
using namespace std;

#define V 6 

int encontrarVerticeMinimo(int chave[], bool mstSet[]) {
    int minimo = INT_MAX, minimoIndex;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && chave[v] < minimo) {
            minimo = chave[v];
            minimoIndex = v;
        }
    }

    return minimoIndex;
}

void exibirMST(int parent[], int graph[V][V]) {
    cout << "Aresta \tPeso" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

void primMST(int graph[V][V]) {
    int arvoreMinima[V];   
    int chave[V];    
    bool mstSet[V]; 

    
    for (int i = 0; i < V; i++) {
        chave[i] = INT_MAX;
        mstSet[i] = false;
    }

    chave[0] = 0;       
    arvoreMinima[0] = -1;    

    for (int count = 0; count < V - 1; count++) {
        int u = encontrarVerticeMinimo(chave, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < chave[v]) {
                arvoreMinima[v] = u;
                chave[v] = graph[u][v];
            }
        }
    }

    exibirMST(arvoreMinima, graph);
}

int main() {
    int graph[V][V] = {
        { 0, 2, 0, 6, 0, 3 },
        { 2, 0, 3, 8, 5, 0 },
        { 0, 3, 0, 0, 7, 0 },
        { 6, 8, 0, 0, 9, 4 },
        { 0, 5, 7, 9, 0, 2 },
        { 3, 0, 0, 4, 2, 0 }
    };

    primMST(graph);

    return 0;
}

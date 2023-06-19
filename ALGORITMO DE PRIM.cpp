#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Aresta {
    int origem, destino, peso;
};

void exibirMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Aresta \tPeso" << endl;
    int custoTotal = 0;
    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        custoTotal += graph[i][parent[i]];
    }
    cout << "Custo total da arvore: " << custoTotal << endl;
}

bool temCiclo(int u, vector<int>& parent) {
    while (parent[u] != -1) {
        if (u == parent[u])
            return true;
        u = parent[u];
    }
    return false;
}

int encontrarVerticeMinimo(vector<int>& chave, vector<bool>& mstSet) {
    int minimo = INT_MAX, minimoIndice;

    for (int v = 0; v < chave.size(); v++) {
        if (mstSet[v] == false && chave[v] < minimo) {
            minimo = chave[v];
            minimoIndice = v;
        }
    }

    return minimoIndice;
}

void primMST(vector<vector<int>>& arestas, int numVertices) {
    vector<int> arvoreMinima(numVertices, -1);
    vector<int> chave(numVertices, INT_MAX);
    vector<bool> mstSet(numVertices, false);

    chave[0] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = encontrarVerticeMinimo(chave, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (arestas[u][v] && mstSet[v] == false && arestas[u][v] < chave[v] && !temCiclo(u, arvoreMinima)) {
                arvoreMinima[v] = u;
                chave[v] = arestas[u][v];
            }
        }
    }

    exibirMST(arvoreMinima, arestas);
}

int main() {
    vector<Aresta> arestas = {
        {0, 1, 2},
        {0, 3, 6},
        {0, 5, 3},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9},
        {3, 5, 4},
        {4, 5, 2}
    };

    int numVertices = 6;
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    for (const auto& aresta : arestas) {
        graph[aresta.origem][aresta.destino] = aresta.peso;
        graph[aresta.destino][aresta.origem] = aresta.peso;
    }

    primMST(graph, numVertices);

    return 0;
}

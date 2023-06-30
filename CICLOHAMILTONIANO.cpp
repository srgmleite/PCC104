#include <iostream>
#include <vector>

using namespace std;

// Função para verificar se é seguro adicionar o vértice v ao caminho atual
bool isSafe(int v, int pos, vector<int>& path, vector<vector<int>>& graph) {
    // Verifica se v é um vértice adjacente ao último vértice adicionado no caminho
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Verifica se v já está presente no caminho
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Função recursiva para encontrar um ciclo hamiltoniano no grafo
bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    int numVertices = graph.size();

    // Caso base: se todos os vértices foram adicionados ao caminho
    if (pos == numVertices) {
        // Verifica se o último vértice está conectado ao primeiro vértice
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Tenta adicionar vértices ao caminho
    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos, path, graph)) {
            path[pos] = v;

            // Recursivamente encontra um ciclo hamiltoniano a partir do próximo vértice
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            // Caso contrário, remove o vértice v do caminho
            path[pos] = -1;
        }
    }

    return false;
}

// Função principal para encontrar um ciclo hamiltoniano no grafo
void hamiltonianCycle(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> path(numVertices, -1);

    // O vértice 0 é sempre incluído no ciclo hamiltoniano como o primeiro vértice
    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        cout << "Não existe ciclo hamiltoniano no grafo." << endl;
        return;
    }

    cout << "Ciclo Hamiltoniano encontrado: ";
    for (int i = 0; i < numVertices; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    int numVertices;
    cout << "Digite o número de vértices do grafo: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    cout << "Digite a matriz de adjacência do grafo:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    hamiltonianCycle(graph);

    return 0;
}

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct Node {
    vector<int> path;
    int bound;
    int level;
    int cost;

    Node(const vector<int>& path, int bound, int level, int cost) :
        path(path), bound(bound), level(level), cost(cost) {}
};

struct NodeComparator {
    bool operator()(const Node& a, const Node& b) {
        return a.bound > b.bound;
    }
};

int calculateBound(const vector<vector<int>>& distancias, const Node& node) {
    int bound = node.cost;

    for (int i = 0; i < distancias.size(); i++) {
        if (find(node.path.begin(), node.path.end(), i) == node.path.end()) {
            int minDist = numeric_limits<int>::max();
            for (int j = 0; j < distancias.size(); j++) {
                if (i != j && distancias[i][j] < minDist) {
                    minDist = distancias[i][j];
                }
            }
            bound += minDist;
        }
    }

    return bound;
}

int branchAndBound(const vector<vector<int>>& distancias, vector<int>& melhor_permutacao) {
    int num_cidades = distancias.size();
    vector<int> initialPath{ 0 };
    int initialBound = calculateBound(distancias, Node(initialPath, 0, 0, 0));
    priority_queue<Node, vector<Node>, NodeComparator> pq;
    pq.push(Node(initialPath, initialBound, 0, 0));
    int bestDistance = numeric_limits<int>::max();

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int level = current.level;
        int cost = current.cost;
        vector<int> path = current.path;

        if (level == num_cidades - 1) {
            int distance = cost + distancias[path[level]][0];
            if (distance < bestDistance) {
                bestDistance = distance;
                melhor_permutacao = path;
            }
        }

        for (int i = 1; i < num_cidades; i++) {
            if (find(path.begin(), path.end(), i) == path.end()) {
                vector<int> newPath = path;
                newPath.push_back(i);
                int newCost = cost + distancias[path[level]][i];
                int newBound = calculateBound(distancias, Node(newPath, 0, level + 1, newCost));

                if (newBound < bestDistance) {
                    pq.push(Node(newPath, newBound, level + 1, newCost));
                }
            }
        }
    }

    return bestDistance;
}

int main() {
    int num_cidades;
    cout << "Digite o número de cidades: ";
    cin >> num_cidades;

    vector<string> nomes_cidades(num_cidades);
    for (int i = 0; i < num_cidades; i++) {
        cout << "Digite o nome da cidade " << i + 1 << ": ";
        cin >> nomes_cidades[i];
    }

    vector<vector<int>> distancias(num_cidades, vector<int>(num_cidades));
    bool simetricas;
    cout << "As distâncias entre as cidades são simétricas? (Digite 1 para sim ou 0 para não): ";
    cin >> simetricas;

    if (simetricas) {
        for (int i = 0; i < num_cidades; i++) {
            for (int j = i + 1; j < num_cidades; j++) {
                cout << "Digite a distância entre " << nomes_cidades[i] << " e " << nomes_cidades[j] << ": ";
                int distancia;
                cin >> distancia;
                distancias[i][j] = distancia;
                distancias[j][i] = distancia;
            }
        }
    }
    else {
        for (int i = 0; i < num_cidades; i++) {
            for (int j = 0; j < num_cidades; j++) {
                if (i != j) {
                    cout << "Digite a distância entre " << nomes_cidades[i] << " e " << nomes_cidades[j] << ": ";
                    cin >> distancias[i][j];
                }
            }
        }
    }

    vector<int> melhor_permutacao;
    int melhor_caminho = branchAndBound(distancias, melhor_permutacao);

    cout << "Menor distância encontrada: " << melhor_caminho << endl;

    cout << "Caminho percorrido: ";
    cout << nomes_cidades[0];
    for (int i = 0; i < num_cidades - 1; i++) {
        cout << " -> " << nomes_cidades[melhor_permutacao[i]];
    }
    cout << " -> " << nomes_cidades[0] << endl;

    return 0;
}

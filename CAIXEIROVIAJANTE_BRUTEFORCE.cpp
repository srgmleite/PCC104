#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

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

    vector<int> permutacao;
    for (int i = 1; i < num_cidades; i++) {
        permutacao.push_back(i);
    }

    int melhor_caminho = numeric_limits<int>::max();
    vector<int> melhor_permutacao;

    do {
        int comprimento_total = 0;
        int cidade_origem = 0;

        for (int i = 0; i < num_cidades - 1; i++) {
            int cidade_destino = permutacao[i];
            comprimento_total += distancias[cidade_origem][cidade_destino];
            cidade_origem = cidade_destino;
        }

        comprimento_total += distancias[cidade_origem][0];

        if (comprimento_total < melhor_caminho) {
            melhor_caminho = comprimento_total;
            melhor_permutacao = permutacao;
        }

    } while (next_permutation(permutacao.begin(), permutacao.end()));

    cout << "Menor distância encontrada: " << melhor_caminho << endl;

    cout << "Caminho percorrido: ";
    cout << nomes_cidades[0];
    for (int i = 0; i < num_cidades - 1; i++) {
        cout << " -> " << nomes_cidades[melhor_permutacao[i]];
    }
    cout << " -> " << nomes_cidades[0] << endl;

    return 0;
}

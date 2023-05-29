#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = -1e9;
vector<vector<int>> dpTabela;

int mochila(int PesoMax, vector<int>& valores, vector<int>& pesos, int itens) {
    if (itens == 0 || PesoMax == 0) {
        return 0;
    }

    if (dpTabela[itens][PesoMax] != -1) {
        return dpTabela[itens][PesoMax];
    }

    if (pesos[n - 1] > PesoMax) {
        dpTabela[itens][PesoMax] = mochila(PesoMax, valores, pesos, itens - 1);
        return dpTabela[itens][PesoMax];
    }
    else {
        dpTabela[itens][PesoMax] = max(valores[itens - 1] + mochila(PesoMax - pesos[itens - 1], valores, pesos, itens - 1), mochila(PesoMax, valores, pesos, itens - 1));
        return dpTabela[itens][PesoMax];
    }
}

int main() {
    int itens, PesoMax;
    cout << "Insira o n�mero de itens: ";
    cin >> itens;

    vector<int> valores(itens);
    vector<int> pesos(itens);
    cout << "Insira os valores e pesos dos itens:" << endl;
    for (int i = 0; i < itens; i++) {
        cin >> valores[i] >> pesos[i];
    }

    cout << "Insira a capacidade m�xima da mochila: ";
    cin >> PesoMax;

    dpTable.resize(itens + 1, vector<int>(PesoMax + 1, -1));

    int maxValor = mochilar(PesoMax, valores, pesos, itens);
    cout << "O valor m�ximo poss�vel de ser obtido: " << maxValor << endl;

    return0;
}
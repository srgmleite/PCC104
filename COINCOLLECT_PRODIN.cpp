#include<iostream>
#include<vector>
using namespace std;

const int INF = -1e9;

int cataMoeda(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dpTabela(n, vector<int>(m, INF));
    dpTabela[0][0] = grid[0][0];

    for (int j = 1; j < m; j++) {
        dpTabela[0][j] = dpTabela[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < n; i++) {
        dpTabela[i][0] = dpTabela[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dpTabela[i][j] = max(dpTabela[i - 1][j], dpTabela[i][j - 1]) + grid[i][j];
        }
    }

    return dpTabela[n - 1][m - 1];
}

int main() {
    int n, m;
    cout << "Insira o número de linhas e colunas: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Insira os elementos do grid:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int maxMoedas = cataMoeda(grid);
    cout << "O número máximo de moedas coletadas foi: " << maxMoedas << endl;

    return 0;
}

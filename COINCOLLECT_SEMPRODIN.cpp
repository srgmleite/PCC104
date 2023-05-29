#include<iostream>
#include<vector>
using namespace std;

int cataMoeda(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int lin = 0, col = 0;
    int moedas_coletadas = 0;

    while (lin != m - 1 || col != n - 1) {
        moedas_coletadas += grid[lin][col];
        if (grid[lin + 1][col] > grid[lin][col + 1]) {
            lin++;
        }
        else {
            col++;
        }
    }

    moedas_coletadas += grid[m - 1][n - 1];
    return moedas_coletadas;
}

int main() {
    int m, n;
    cout << "Insira a dimens�o do grid: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Insira os valores das moedas em cada c�lula do grid:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int moedas_coletadas = cataMoeda(grid);
    cout << "O m�ximo de moedas que podem ser coletadas � de: " << moedas_coletadas << endl;

    return0;
}

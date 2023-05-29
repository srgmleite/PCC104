#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> denom = { 5, 10, 25, 50, 100 };
const int INF = INT_MAX;

int fazTroco(int quantia) {
    vector<int> dpTable(quantia + 1, INF); 
    dpTable[0] = 0;  
    for (int i = 1; i <= quantia; i++) {  
        for (int j = 0; j < denom.size(); j++) {
            if (denom[j] <= i) {
                int subProb = dpTable[i - denom[j]];
                if (subProb != INF && subProb + 1 < dpTable[i]) {
                    dpTable[i] = subProb + 1;  
                }
            }
        }
    }

    if (dpTable[quantia] != INT_MAX) {
        return dpTable[quantia]; 
    }
    else {
        return -1;  
    }
}

int main() {
    int quantia;
    cout << "Insira a quantia: ";
    cin >> quantia;

    int minMoedas = fazTroco(quantia);
    if (minMoedas != -1) {
        cout << "Mínimo de moedas necessárias: " << minMoedas << endl;
    }
    else {
        cout << "Não foi possível realizar o troco com a quantia declarada." << endl;
    }

    return 0;
}

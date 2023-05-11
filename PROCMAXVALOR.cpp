#include <iostream>
using namespace std;

int findMaxPosition(int arr[], int left, int right) {
    // Caso base: arr tem apenas um elemento
    if (left == right) {
        return left;
    }

    // Divide o arranjo em dois subarranjos
    int mid = (left + right) / 2;
    int maxLeft = findMaxPosition(arr, left, mid);
    int maxRight = findMaxPosition(arr, mid + 1, right);

    // Encontra o índice do maior elemento entre os subarranjos
    if (arr[maxLeft] > arr[maxRight]) {
        return maxLeft;
    }
    else {
        return maxRight;
    }
}

int main() {
    int n;
    cout << "Digite o tamanho do arranjo: ";
    cin >> n;

    int arr[n];
    cout << "Digite os elementos do arranjo: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxPosition = findMaxPosition(arr, 0, n - 1);
    cout << "A posição do maior elemento é " << maxPosition << endl;

    return 0;
}

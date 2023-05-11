#include <iostream>
#include <vector>

using namespace std;

// função que implementa o QuickSort recursivamente
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // seleciona o pivô
        int pivot = arr[high];

        // divide o arranjo em dois subarranjos
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        // chama o QuickSort recursivamente para ordenar os subarranjos
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// função que imprime um arranjo
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 10, 7, 8, 9, 1, 5 };
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Arranjo ordenado:" << endl;
    printArray(arr);

    return 0;
}

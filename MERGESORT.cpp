#include <iostream>
#include <vector>

using namespace std;

// função que combina dois subarranjos ordenados em um arranjo ordenado
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> merged;

    // combina os elementos dos subarranjos em um arranjo ordenado
    while (!left.empty() && !right.empty()) {
        if (left[0] <= right[0]) {
            merged.push_back(left[0]);
            left.erase(left.begin());
        }
        else {
            merged.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    // copia os elementos restantes do subarranjo esquerdo
    while (!left.empty()) {
        merged.push_back(left[0]);
        left.erase(left.begin());
    }

    // copia os elementos restantes do subarranjo direito
    while (!right.empty()) {
        merged.push_back(right[0]);
        right.erase(right.begin());
    }

    return merged;
}

// função que implementa o Merge Sort recursivamente
vector<int> mergeSort(vector<int> arr) {
    int n = arr.size();

    if (n <= 1) {
        return arr;
    }

    // encontra o índice do meio do arranjo
    int mid = n / 2;

    // divide o arranjo em dois subarranjos
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // ordena os subarranjos recursivamente
    left = mergeSort(left);
    right = mergeSort(right);

    // combina os subarranjos em um arranjo ordenado
    return merge(left, right);
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
    arr = mergeSort(arr);

    cout << "Arranjo ordenado:" << endl;
    printArray(arr);

    return 0;
}


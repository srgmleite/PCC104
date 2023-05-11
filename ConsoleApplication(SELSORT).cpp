#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector <int>& arr)
{
    int valA, valB, auxiliar;


    for (valA = 0; valA < arr.size() - 1; valA++) {
        auxiliar = valA;

        for (valB = valA + 1; valB < arr.size() - 1; valB++)
            if (arr[valB] < arr[auxiliar])
                auxiliar = valB;
        swap(arr[auxiliar], arr[valA]);
    }
}

void printArray(vector <int>& arr)
{
    int valA;
    for (valA = 0; valA < arr.size() - 1; valA++)
        cout << arr[valA] << " ";
    cout << endl;
}

int main() {
    vector <int> arr {3,5,7,2,7,13,8};
    selectionSort(arr);
    printArray(arr);
}
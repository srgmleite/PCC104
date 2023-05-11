#include <iostream> 
#include <vector>
using namespace std;

int sequentialSearch(vector<int> A, int K)
{
    int i = 0;
    while (i < A.size()) {
        if (A[i] != K) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    vector <int> A{ 1, 5, 8, 2, 6, 7, 3, 4, 2, 0 };
    int K = 5;
    int position = sequentialSearch(A, K);

    if (position == -1)
        cout << "Element not found";
    else
        cout << "Element Found at Position: " << position;
    return 0;
}
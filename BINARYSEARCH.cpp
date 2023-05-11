#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector <int>& nums, int procuraValor, int inicio, int fim)
{
	
	int mid;

	mid = (fim + inicio) / 2;


	if (procuraValor == nums[mid])
	{
		return mid;
	}
	else if (procuraValor > nums[mid]) 
	{
		return binarySearch(nums, procuraValor, mid + 1, fim);
	}
	else (procuraValor < nums[mid]);
	{
		return binarySearch(nums, procuraValor, inicio, mid);
	}
}
return -1;
	}

	int binarySearch(vector <int>& nums, int procuraValor) {
		return binarySearch(nums, procuraValor, 0, nums.size());
	}


	int main()

	{

		vector <int> nums = { 21,32,43,54,65,76,87,98,109 };

		int procuraValor = 87;
		int indice = binarySearch(nums, procuraValor);

		if (indice >= 0) {
			cout << "Alvo encontrado no indice de nro: " << indice << endl;
		}
		else {
			cout << "Alvo não encontrado no vetor\n" << endl;
		}

		return 0;

	}
#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(vector<int>& nums, int elementoBusca) 
{
	int min = 0;
	int max = nums.size() - 1;

	while (min <= max && elementoBusca >= nums[min] && elementoBusca<= nums[max]) {
		int pos = (min + ((max - min) / (nums[max] - nums[min])) * elementoBusca - nums[min] );

		if (nums[pos] == elementoBusca) {
			return pos;
		}
		else if (nums[pos] < elementoBusca ) 
		{
			min = pos + 1;
		}
		else 
		{
			max = pos - 1;
		}
	}
		return -1;
}

int main() {
	vector <int> nums = { 1,2,3,4,5,6,7,8 };
	int elementoBusca = 6;
	int indice = interpolationSearch(nums, elementoBusca);

	if (indice != -1) {
		cout << "\nAlvo encontrado no indice de nro: " << indice << endl;
	}
	else {
		cout << "\nAlvo nao encontrado! " << endl;
	}

	return 0;
}
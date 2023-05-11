#include <iostream>
#include <vector>
using namespace std

int BinarySearch(std::vector<int> a, int k); {
	int l = 0;
	int r = a(a.size() - 1);

	while (l <= r) {
		int m = (l + r) / 2;
		if (k = a[m]) {
			return m;
		}
		else if (k < a[m]) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return-1;
}

#include <iostream>
using namespace std;

int a[1100000];
int d_sum(int k) {
	int ret = k;
	while (k > 0) {
		ret += k % 10;
		k /= 10;
	}
	return ret;
}
int main()
{
	for (int i = 1; i <= 1000000; i++) {
		int ds = d_sum(i);
		if (a[ds] == 0) {
			a[ds] = i;
		}
	}
	int n;
	cin >> n;
	cout << a[n];
	return 0;
}
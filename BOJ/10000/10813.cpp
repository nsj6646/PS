#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}
	while (M--) {
		int i, j;
		cin >> i >> j;
		swap(v[i-1], v[j-1]);
	}
	for (int x : v) {
		cout << x << ' ';
	}
	return 0;
}
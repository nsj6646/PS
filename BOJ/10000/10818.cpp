#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cout << *min_element(v.begin(), v.end()) << ' ' << *max_element(v.begin(), v.end());
	return 0;
}
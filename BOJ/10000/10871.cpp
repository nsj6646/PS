#include <iostream>

using namespace std;
int A[10000];
int main()
{
	int N, X;
	cin >> N >> X;
	auto is_less = [&](int number) {
		return number < X;
	};
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (is_less(num)) {
			cout << num << ' ';
		}
	}
	return 0;
}
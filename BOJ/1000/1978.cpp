#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num, count = N;
	while (N--) {
		cin>>num;
		if (num<2) {
			continue;
		}
		for (int i = 2; i*i <= num; i++) {
			if (num%i == 0) {
				count--;
				break;
			}
		}

	}
	printf("%d", count);
	return 0;
}
/*
#include <iostream>
using namespace std;
bool is_prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i<n; i++) {
		int num;
		cin >> num;
		if (is_prime(num)) {
			cnt += 1;
		}
	}

	cout << cnt << '\n';
	return 0;
}
*/
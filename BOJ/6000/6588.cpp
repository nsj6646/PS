#define MAX 1000000
#include <cstdio>

bool p[MAX +1];

int main()
{
	for (int i = 2; i*i <= MAX; i++) {
		if (p[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				p[j] = true;
			}
		}
	}
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 3; i * 2 <= n; i+=2) {
			if (p[i] == false && p[n - i] == false) {
				printf("%d = %d + %d\n", n, i, n - i);
				//cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}
	return 0;
}
//
//#include <iostream>
//using namespace std;
//const int max = 1000000;
//int prime[max];
//int pn;
//bool check[max + 1]; // true: 지워진것 (소수가 아님), false: 지워지지 않음 (소수)
//int main() {
//	for (int i = 2; i <= max; i++) {
//		if (check[i] == false) {
//			prime[pn++] = i;
//			for (int j = i + i; j <= max; j += i) {
//				check[j] = true;
//			}
//		}
//	}
//	while (true) {
//		int n;
//		cin >> n;
//		if (n == 0) {
//			break;
//		}
//		for (int i = 1; i < pn; i++) {
//			if (check[n - prime[i]] == false) {
//				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
//				break;
//			}
//		}
//	}
//	return 0;
//}

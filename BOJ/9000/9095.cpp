#include <cstdio>

int d[11];
int plus(int n);
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", plus(n));
	}
	return 0;
}
int plus(int n) {
	if (n ==1) {
		d[n] = 1;
		return 1;
	}
	else if (n == 2) {
		d[n] = plus(n - 1) + 1;
		return d[n];
	}
	else if (n == 3) {
		d[n] = plus(n - 1) + plus(n - 2) + 1;
		return d[n];
	}
	else {
		if (d[n] < 1) {
			d[n] = plus(n - 1) + plus(n - 2) + plus(n - 3);
			return d[n];
		}
		else {
			return d[n];
		}
	}
}
//#include <iostream>
//using namespace std;
//int go(int count, int sum, int goal) {
//	if (count > 10) {
//		return 0;
//	}
//	if (sum > goal) {
//		return 0;
//	}
//	if (sum == goal) {
//		return 1;
//	}
//	int now = 0;
//	for (int i = 1; i <= 3; i++) {
//		now += go(count + 1, sum + i, goal);
//	}
//	return now;
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		cout << go(0, 0, n) << '\n';
//	}
//	return 0;
//}
/*
#include <stdio.h>
int d[11];
int main() {
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
}
*/
//#include <cstdio>
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		int ans = 0;
//		int n;
//		scanf("%d", &n);
//		for (int l1 = 1; l1 <= 3; l1++) {
//			if (l1 == n) {
//				ans += 1;
//			}
//			for (int l2 = 1; l2 <= 3; l2++) {
//				if (l1 + l2 == n) {
//					ans += 1;
//				}
//				for (int l3 = 1; l3 <= 3; l3++) {
//					if (l1 + l2 + l3 == n) {
//						ans += 1;
//					}
//					for (int l4 = 1; l4 <= 3; l4++) {
//						if (l1 + l2 + l3 + l4 == n) {
//							ans += 1;
//						}
//						for (int l5 = 1; l5 <= 3; l5++) {
//							if (l1 + l2 + l3 + l4 + l5 == n) {
//								ans += 1;
//							}
//							for (int l6 = 1; l6 <= 3; l6++) {
//								if (l1 + l2 + l3 + l4 + l5 + l6 == n) {
//									ans += 1;
//								}
//								for (int l7 = 1; l7 <= 3; l7++) {
//									if (l1 + l2 + l3 + l4 + l5 + l6 + l7 == n) {
//										ans += 1;
//									}
//									for (int l8 = 1; l8 <= 3; l8++) {
//										if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == n) {
//											ans += 1;
//										}
//										for (int l9 = 1; l9 <= 3; l9++) {
//											if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == n) {
//												ans += 1;
//											}
//											for (int l0 = 1; l0 <= 3; l0++) {
//												if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l0 == n) {
//													ans += 1;
//												}
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int go(int n) {
//	if (n < 0) {
//		return 0;
//	}
//	if (n == 0) {
//		return 1;
//	}
//	return go(n - 1) + go(n - 2) + go(n - 3);
//}
//int main()
//{
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		int n;
//		cin >> n;
//		cout << go(n) << '\n';
//	}
//	return 0;
//}
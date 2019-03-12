//#include <cstdio>
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		printf("%d\n", a + b);
//	}
//	return 0;
//}
#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a, b;
		cout << a + b;
	}
	return 0;
}
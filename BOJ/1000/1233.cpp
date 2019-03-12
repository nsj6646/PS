//#include <iostream>
//#include <set>
//
//using namespace std;
//
////int s1[21], s2[21], s3[41];
//
//int main()
//{
//	multiset<int> ms;
//	int a, b, c;
//	cin >> a >> b >> c;
//	for (int i = 1; i <= a; i++) {
//		for (int j = 1; j <= b; j++) {
//			for (int k = 1; k <= c; k++) {
//				ms.insert(i + j + k);
//			}
//		}
//	}
//	int ans = -1;
//	for (int x : ms) {
//		ans = ms.count(x) > ms.count(ans) ? x : ans;
//	}
//	cout << ans;
//	return 0;
//}
#include <iostream>
using namespace std;
int s[81];
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				s[i + j + k] += 1;

	int n = 0;
	for (int i = 1; i < a + b + c; i++)
		n = s[i] > s[n] ? i : n;
	cout << n;
}
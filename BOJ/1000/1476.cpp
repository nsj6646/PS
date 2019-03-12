//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int e, s, m;
//	cin >> e >> s >> m;
//	int a = 0, b = 0, c = 0;
//	for (int i = 1; i <= 7980; i++) {
//		if ((i % 15 == e || i % 15 == 0) && (i % 28 == s || i % 28 == 0) && (i % 19 == m || i % 19 == 0)) {
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
int main() {
	int E, S, M;
	cin >> E >> S >> M;
	int e = 1, s = 1, m = 1;
	for (int i = 1;; i++) {
		if (e == E && s == S && m == M) {
			cout << i << '\n';
			break;
		}
		e += 1;
		s += 1;
		m += 1;
		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
long long a[500000];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<pii> s;
	long long ans = 0LL;
	for (int i = 0; i < n; i++) {
		pii p = { a[i],1 };
		if (s.empty()) {
			s.push({ a[i],1 });
			continue;
		}
		if (a[i] < s.top().first) {
			ans += 1LL;
		}
		else if (a[i] >= s.top().first) {
			while (!s.empty() && a[i] >= s.top().first) {
				ans += (long long)s.top().second;
				if (p.first == s.top().first) {
					p.second += s.top().second;
				}
				s.pop();
			}
			if (!s.empty()) {
				ans += 1LL;
			}
		}
		s.push(p);
	}
	cout << ans;
	return 0;
}
//#include <iostream>
//#include <stack>
//using namespace std;
//
//typedef pair<int, int> pii;
//long long a[500000];
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	stack<pii> s;
//	long long ans = 0LL;
//	for (int i = 0; i < n; i++) {
//		pii p = { a[i],1 };
//		while (!s.empty()) {
//			if (s.top().first <= a[i]) {
//				ans += (long long)s.top().second;
//				if (s.top().first == a[i]) {
//					p.second += s.top().second;
//				}
//				s.pop();
//			}
//			else {
//				break;
//			}
//		}
//		if (!s.empty()) {
//			ans += 1LL;
//		}
//		s.push(p);
//	}
//	cout << ans;
//	return 0;
//}
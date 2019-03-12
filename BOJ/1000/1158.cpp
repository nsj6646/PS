//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//queue<int> q;
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		q.push(i);
//	}
//	cout << '<';
//	while (true) {
//		for (int i = 1; i < M; i++) {
//			q.push(q.front());
//			q.pop();
//		}
//		cout << q.front();
//		q.pop();
//		if (!q.empty()) {
//			cout << ", ";
//		}
//		else {
//			break;
//		}
//	}
//	cout << '>';
//	return 0;
//}
//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> l;
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		l.push_back(i);
//	}
//	auto it = l.begin();
//	cout << '<';
//	while (l.size()>1) {
//		int mod = m%l.size() ? m%l.size() : m;
//		for (int i = 1; i <mod; i++) {
//			++it;
//			if (it == l.end()) {
//				it = l.begin();
//			}
//		}
//		cout << *it << ", ";
//		auto temp = it;
//		++it;
//		if (it == l.end()) {
//			it = l.begin();
//		}
//		l.erase(temp);
//	}
//	cout << l.front() << '>';
//	return 0;
//}
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	cout << '<';
	int i = -1;
	while (true) {
		i = (i + M) % N;
		cout << v[i];
		v.erase(v.begin() + i);
		i -= 1;
		N--;
		if (!v.empty()) {
			cout << ", ";
		}
		else {
			break;
		}
	}
	cout << '>';
	return 0;
}
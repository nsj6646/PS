#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	int num;
	set<int> s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		s.insert(num);
	}
	for (auto x : s) {
		cout << x << ' ';
	}
	//for (auto it = s.begin(); it != s.end(); ++it) {
	//	cout << *it;
	//}
	return 0;
}
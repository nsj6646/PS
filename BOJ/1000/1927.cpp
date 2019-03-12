#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int> mh;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (mh.empty()) {
				cout << "0\n";
			}
			else {
				cout << -mh.top() << '\n';
				mh.pop();
			}
		}
		else {
			mh.push(-x);
		}
	}
	return 0;
}
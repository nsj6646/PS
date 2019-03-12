#include <iostream>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int ans;
deque<int> d;
void move_left() {
	d.push_back(d.front());
	d.pop_front();
	ans += 1;
}
void move_right() {
	d.push_front(d.back());
	d.pop_back();
	ans += 1;
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		d.push_back(i + 1);
	}
	queue<int> q;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (!q.empty()) {
		if (d.front() == q.front()) {
			d.pop_front();
			q.pop();
		}
		else {
			auto it = find(d.begin(), d.end(), q.front());
			if (it - d.begin() <= d.end() - it) {
				while (d.front() != q.front()) {
					move_left();
				}
			}
			else {
				while (d.front() != q.front()) {
					move_right();
				}
			}
		}
	}
	cout << ans;
	return 0;
}
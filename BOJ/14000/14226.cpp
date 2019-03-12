#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> state;
set<state> visited;

int main()
{
	ios::sync_with_stdio(false);
	int s;
	cin >> s;

	int t = 0;
	queue<state> q;
	q.push({ 1,0 });
	visited.insert({ 1,0 });
	while (!q.empty()) {
		int sz = q.size();
		t += 1;
		for (int i = 0; i < sz; ++i) {
			state now = q.front();
			q.pop();
			if (now.first == s) {
				cout << t-1 << '\n';
				return 0;
			}

			state next[3] = { { now.first,now.first },{now.first + now.second,now.second},{now.first - 1,now.second} };
			for (int k = 0; k < 3;++k){
				if (visited.count(next[k]) == 0) {
					visited.insert(next[k]);
					q.push(next[k]);
				}
			}
		}
	}
	return 0;
}
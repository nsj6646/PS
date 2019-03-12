#include <iostream>
#include <map>
#include <queue>
#include <string>
#define ACCEPT 123456789
using namespace std;

int puzzle[3][3];
int dx[] = { 0,0,-1,1, };
int dy[] = { 1,-1,0,0 };

pair<int, int> find(string now) {
	int z=now.find('9');
	int x = z % 3, y = z / 3;
	return make_pair(x, y);
}

void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
int main()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> puzzle[i][j];
			if (puzzle[i][j] == 0) {
				puzzle[i][j] = 9;
			}
		}
	}
	int start = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			start = start * 10 + puzzle[i][j];
		}
	}
	//bfs
	queue<int> q;
	map<int, int> d;
	q.push(start);
	d[start] = 0;
	while (!q.empty()) {
		int now = q.front();
		if (now == ACCEPT) {
			cout << d[now];
			return 0;
		}
		string now_state = to_string(now);
		q.pop();
		for (int k = 0; k < 4; k++) {
			pair<int, int> pos = find(now_state);
			int nx = pos.second + dx[k];
			int ny = pos.first + dy[k];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next_state = now_state;
				swap(next_state[3*pos.second+pos.first],next_state[3*nx+ny]);
				int next = stoi(next_state);
				if (d.count(next)==0) {
					d[next] = d[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << -1;


	return 0;
}

//#include <iostream>
//#include <queue>
//#include <string>
//#include <map>
//using namespace std;
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//int main() {
//	int n = 3;
//	int start = 0;
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			int temp;
//			cin >> temp;
//			if (temp == 0) {
//				temp = 9;
//			}
//			start = start * 10 + temp;
//		}
//	}
//	queue<int> q;
//	map<int, int> dist;
//	dist[start] = 0;
//	q.push(start);
//	while (!q.empty()) {
//		int now_num = q.front();
//		string now = to_string(now_num);
//		q.pop();
//		int z = now.find('9');
//		int x = z / 3;
//		int y = z % 3;
//		for (int k = 0; k<4; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//				string next = now;
//				swap(next[x * 3 + y], next[nx * 3 + ny]);
//				int num = stoi(next);
//				if (dist.count(num) == 0) {
//					dist[num] = dist[now_num] + 1;
//					q.push(num);
//				}
//			}
//		}
//	}
//	if (dist.count(123456789) == 0) {
//		cout << -1 << '\n';
//	}
//	else {
//		cout << dist[123456789] << '\n';
//	}
//	return 0;
//}
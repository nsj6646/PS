//#include <iostream>
//#include <cstring>
//#include <set>
//using namespace std;
//
//int n, m;
//char map[1000][1001];
//bool visited[1000][1000];
//int check[1000][1000];
//set<int> s;
//void move(int x, int y) {
//	if (visited[x][y]) {
//		return;
//	}
//	visited[x][y] = true;
//	s.insert(check[x][y]);
//	switch (map[x][y]) {
//	case 'N':
//		move(x - 1, y);
//		break;
//	case 'W':
//		move(x, y-1);
//		break;
//	case 'E':
//		move(x , y+1);
//		break;
//	case 'S':
//		move(x +1, y);
//		break;
//	}
//}
//
//void printall() {
//	cout << '\n';
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << check[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//void init() {
//	for (int i = 0; i < n; i++) {
//		memset(visited[i], false, sizeof(bool)*m);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	int a = 1;
//	for (int i = 0; i < n; i++) {
//		cin >> map[i];
//		for (int j = 0; j < m; j++) {
//			check[i][j] = a++;
//		}
//	}
//
//	//cout << '\n';
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = 0; j < m; j++) {
//	//		cout << board[i][j] << ' ';
//	//	}
//	//	cout << '\n';
//	//}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			init();
//			int n = s.size();
//			move(i, j);
//			if (n == 0) {
//				continue;
//			}
//			if (n != s.size()) {
//				ans += s.size() - n;
//			}
//		}
//	}
//
//	cout << ans;
//	return 0;
//}
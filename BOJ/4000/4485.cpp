//#include <iostream>
//using namespace std;
//
//int cave[125][125];
//
//int dijkstra(int x, int y) {
//
//}
//int main()
//{
//	int T;
//	for (int tc = 1; tc <= T; tc++) {
//		int n;
//		cin >> n;
//		if (n == 0) {
//			break;
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> cave[i][j];
//			}
//		}
//		cout<<"Problem "<<tc<<": "<<dijkstra(0, 0)<<'\n';
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define N_ 125
#define INT 0x7fffffff
using namespace std;
int n, a[N_][N_], dst[N_][N_], dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
priority_queue<pair<int,pair<int, int>>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 1;
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j], dst[i][j] = INT;
		dst[0][0] = a[0][0];
		pq.push({ -a[0][0],{ 0,0 }});
		while (!pq.empty()) {
			int v_x = pq.top().second.first; int v_y = pq.top().second.second;
			int dis = -pq.top().first;
			pq.pop();
			if (dis > dst[v_x][v_y]) continue;
			for (int i = 0; i < 4; i++) {
				int nx_x = v_x + dx[i]; int ny_y = v_y + dy[i];
				if (nx_x < 0 || nx_x >= n || ny_y < 0 || ny_y >= n) continue;
				int n_dis = dis + a[nx_x][ny_y];
				if (n_dis < dst[nx_x][ny_y]) {
					dst[nx_x][ny_y] = n_dis;
					pq.push({ -n_dis,{ nx_x,ny_y } });
				}
			}
		}
		cout << "Problem " << cnt << ": " << dst[n - 1][n - 1] << '\n';
		cnt++;
	}
	return 0;
}
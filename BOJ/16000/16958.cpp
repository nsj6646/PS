#define INF		2005
#define N		1005
#include <bits/stdc++.h>
using namespace std;

struct city {
	int s, x, y;
	city(int s=0, int x=0, int y=0) :s(s), x(x), y(y) {}
}a[N];							//���ú� ����
vector <int> tel[2];			//�ڷ���Ʈ�� ���� [0]:�׳� [1]:�ڷ���Ʈ
int tel_dist[N];				//[����]�� ���� ����� �ڷ���Ʈ �Ÿ�
int n, t, m;

int get_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int from, int to) {
	/*��-��*/
	if (!a[from].s && !a[to].s) {
		return min(get_distance(a[from].x, a[from].y, a[to].x, a[to].y),tel_dist[from] + t + tel_dist[to]);
	}
	/*��-��*/
	else if (!a[from].s && a[to].s) {
		return min(get_distance(a[from].x, a[from].y, a[to].x, a[to].y), tel_dist[from] + t);
	}
	/*��-��*/
	else if (a[from].s && !a[to].s) {
		return min(get_distance(a[from].x, a[from].y, a[to].x, a[to].y), t + tel_dist[to]);
	}
	/*��-��*/
	else {
		return min(get_distance(a[from].x, a[from].y, a[to].x, a[to].y), t);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		int s, x, y;
		cin >> s >> x >> y;
		a[i] = { s,x,y };
		tel[s].push_back(i);
	}

	for (int i = 0; i < tel[0].size(); ++i) {
		int from = tel[0][i];
		int dist = INF;
		for (int j = 0; j < tel[1].size(); ++j) {
			int to = tel[1][j];
			dist = min(dist, get_distance(a[from].x, a[from].y, a[to].x, a[to].y));
		}
		tel_dist[from] = dist;
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		cout << solve(from, to) << '\n';
	}


	return 0;
}
#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> point;
list<point> snake;
int a[101][101];
char timer[10001];
int n, k, l;
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };
/*
1:╩С
2:©Л
3:го
4:аб
*/
int ans = 0;
int curve(int d, char c) {
	if (c == 'D') {
		return 1 + (d % 4);
	}
	else {
		return (d - 1) == 0 ? 4 : (d - 1);
	}
}
void solve(int t) {
	int head_x = snake.front().first;
	int head_y = snake.front().second;
	int end_x = snake.back().first;
	int end_y = snake.back().second;
	int d = a[head_x][head_y];
	while (++t) {
		d = a[head_x][head_y];
		head_x += dx[d];
		head_y += dy[d];
		if (head_x >= 1 && head_x <= n && head_y >= 1 && head_y <= n && (a[head_x][head_y] == 0 || a[head_x][head_y] == 5)) {
			if (a[head_x][head_y] == 5) {
				snake.push_front({ head_x,head_y });
				a[head_x][head_y] = d;
			}
			else {
				/*move*/
				for (point &p : snake) {
					int x = p.first;
					int y = p.second;
					p.first += dx[a[x][y]];
					p.second += dy[a[x][y]];
				}
				a[end_x][end_y] = 0;
				end_x = snake.back().first;
				end_y = snake.back().second;
			}
			a[head_x][head_y] = d;
		}
		else {
			ans = t;
			break;
		}
		if (timer[t] == 'D' || timer[t] == 'L') {
			a[head_x][head_y] = curve(d, timer[t]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		a[r][c] = 5;
	}
	cin >> l;

	a[1][1] = 2;
	snake.push_back({ 1,1 });
	for (int i = 0; i < l; i++) {
		int t;
		char c;
		cin >> t >> c;
		timer[t] = c;
	}
	solve(0);

	cout << ans;
	return 0;
}
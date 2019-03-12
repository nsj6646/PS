#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[10][10];
bool visited[10][10];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int ans = 3000;
bool check(int x, int y) {
	for (int k = 0; k < 5; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (visited[ny][nx]) {	//«œ≥™∂Ûµµ ∞„ƒ°∏È æ»µ 
			return false;
		}
	}
	return true;
}

void flower(int cnt, int price) {
	if (cnt > 3) {		//≤…¿∫ 3º€¿Ã∏∏ Ω…¥¬¥Ÿ.
		ans = min(ans, price);
		return;
	}
	for (int y = 1; y < n - 1; y++) {
		for (int x = 1; x < n - 1; x++) {
			if (check(x, y)) {		//≤…¿ª Ω…¿ª ºˆ ¿÷¿∏∏È
				for (int k = 0; k < 5; k++) {	//≤…¿Ÿ
					int nx = x + dx[k];
					int ny = y + dy[k];
					visited[ny][nx] = true;
					price += map[ny][nx];
				}
				//for (int i = 0; i < n; i++) {
				//	for (int j = 0; j < n; j++) {
				//		cout << visited[i][j] << ' ';
				//	}
				//	cout << '\n';
				//}
				//cout << '\n';

				flower(cnt + 1, price);

				//backtracking
				for (int k = 0; k < 5; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					visited[ny][nx] = false;
					price -= map[ny][nx];
				}
			}
		}
	}

	return;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	flower(1, 0);

	cout << ans;
	return 0;
}
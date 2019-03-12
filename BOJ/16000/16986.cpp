#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10][10];		//0:진다 1: 비긴다 2: 이긴다
int player[4][21];	//[누가][이번턴에] 뭘낼지
int idx[4];			//[누가] 몇번째 참여인지
int win[4];			//[누가] 몇번 이겼는지
int used;
int all;
void dfs(int w, int c) {
	if (win[1] == k) {
		cout << 1;
		exit(0);
	}
	if (used == all) {
		return;
	}
	if (win[2] == k || win[3] == k) {
		return;
	}
	if (w > c) {
		swap(w, c);
	}
	if (w == 1) {
		for (int i = 1; i <= n; ++i) {
			if (used&(1 << (i - 1))) continue;
			used |= 1 << (i - 1);
			if (a[i][player[c][idx[c]]] == 2) {
				win[w] += 1;
				idx[c] += 1;
				dfs(w, 6 - w - c);
				win[w] -= 1;
				idx[c] -= 1;
			}
			else {
				win[c] += 1;
				idx[c] += 1;
				dfs(c, 6 - w - c);
				win[c] -= 1;
				idx[c] -= 1;
			}
			used ^= 1 << (i - 1);
		}
	}
	else {
		if (a[player[w][idx[w]]][player[c][idx[c]]] == 2) {
			win[w] += 1;
			idx[w] += 1;
			idx[c] += 1;
			dfs(w, 6 - w - c);
			win[w] -= 1;
			idx[w] -= 1;
			idx[c] -= 1;
		}
		else {
			win[c] += 1;
			idx[w] += 1;
			idx[c] += 1;
			dfs(c, 6 - w - c);
			win[c] -= 1;
			idx[w] -= 1;
			idx[c] -= 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 2; i <= 3; ++i) {
		for (int j = 1; j <= 20; ++j) {
			cin >> player[i][j];
		}
	}

	idx[2] = idx[3] = 1;
	all = (1 << n) - 1;
	dfs(1, 2);
	cout << 0;
	return 0;
}
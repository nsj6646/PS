#include <iostream>
#include <algorithm>
using namespace std;

int a[500][500];

//노가다 하다가 지쳐서 결국 질문검색하고 복붙한 테트로미노..
int Tetromino[19][4][2] = {
{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },		//I
{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },		//I 가로방향
{ { 0, 0 },{ 0, 1 },{ 1, 0 },{ 1, 1 } },		//O
{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },		//L
{ { 0, 0 },{ 1, -2 },{ 1, -1 },{ 1, 0 } },		//L
{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },		//L
{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },		//L
{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, -1 } },		//J
{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },		//J
{ { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },		//J
{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },		//J
{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },		//Z
{ { 0, 0 },{ 0, 1 },{ 1, -1 },{ 1, 0 } },		//Z
{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 2, -1 } },		//S
{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },		//S
{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 1 } },		//T
{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 0 } },		//T
{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 1, 1 } },		//T
{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 2, 0 } },		//T
};

int n, m;

int solve(int x, int y) {
	int p_ans = 0;
	for (int t = 0; t < 19; t++) {
		bool possible = true;
		int temp = 0;
		for (int k = 0; k < 4; k++) {
			int nx = x+Tetromino[t][k][0];
			int ny = y+Tetromino[t][k][1];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				temp += a[nx][ny];
			}
			else {
				possible = false;
				break;
			}
		}
		if (possible) {
			p_ans = max(p_ans, temp);
		}
	}
	return p_ans;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans;
	return 0;
}

/*
int solve(int x, int y) {
	int p_ans = 0;

	if (y + 3 < m) {							//ㅁㅁㅁㅁ
		int temp = 0;
		for (int i = y; i <= y + 3; i++) {
			temp += a[x][i];
		}
		p_ans = max(p_ans, temp);
	}
	if (x + 3 < n) {							//ㅁ
		int temp = 0;							//ㅁ
		for (int i = x; i <= x + 3; i++) {		//ㅁ					
			temp += a[i][y];					//ㅁ
		}
		p_ans = max(p_ans, temp);
	}
	if (x + 1 < n&&y + 1 < m) {						//ㅁㅁ
		int temp = 0;							//ㅁㅁ
		for (int i = x; i <= x + 1; i++) {
			for (int j = y; j <= y + 1; j++) {
				temp += a[i][j];
			}
		}
		p_ans = max(p_ans, temp);
	}
	if (x + 2 < n&&y + 1 < m) {					//ㅁ
		int temp = 0;							//ㅁ
		for (int i = x; i <= x + 2; i++) {		//ㅁㅁ
			temp += a[i][y];
		}
		temp += a[x + 2][y + 1];
		p_ans = max(p_ans, temp);
	}
	if (x + 2 < n&&y + 1 < m) {					//  ㅁ
		int temp = 0;							//  ㅁ
		for (int i = x; i <= x + 2; i++) {		//ㅁㅁ
			temp += a[i][y + 1];
		}
		temp += a[x + 2][y];
		p_ans = max(p_ans, temp);
	}
	if (x + 2 < n&&y + 1 < m) {					//ㅁㅁ
		int temp = 0;							//ㅁ
		for (int i = x; i <= x + 2; i++) {		//ㅁ
			temp += a[i][y];
		}
		temp += a[x][y + 1];
		p_ans = max(p_ans, temp);
	}
	if (x + 2 < n&&y + 1 < m) {					//ㅁㅁ
		int temp = 0;							//  ㅁ
		for (int i = x; i <= x + 2; i++) {		//  ㅁ
			temp += a[i][y + 1];
		}
		temp += a[x][y];
		p_ans = max(p_ans, temp);
	}
	if (x + 2 < n&&y + 1 < m) {					//ㅁㅁ
		int temp = 0;							//  ㅁ
		for (int i = x; i <= x + 2; i++) {		//  ㅁ
			temp += a[i][y + 1];
		}
		temp += a[x][y];
		p_ans = max(p_ans, temp);
	}

}
*/
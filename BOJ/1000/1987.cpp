#include <iostream>
#include <algorithm>
using namespace std;

char board[20][21];
bool alpha[26];	//A:0, B:1, ..., Z:25;
int r, c;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans;
int dfs(int x, int y) {
	int ans = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < c&&ny >= 0 && ny < r) {
			if (alpha[board[ny][nx] - 'A'] == false) {
				alpha[board[ny][nx] - 'A'] = true;
				ans=max(ans,dfs(nx, ny));
				alpha[board[ny][nx] - 'A'] = false;
			}
		}
	}
	return ans + 1;
}
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	alpha[board[0][0] - 'A'] = true;
	
	cout << dfs(0, 0);
	return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//char board[20][21];
//bool alpha[26];	//A:0, B:1, ..., Z:25;
//int r, c;
//int dx[] = { 0,0,-1,1 };
//int dy[] = { -1,1,0,0 };
//int ans;
//void dfs(int x, int y,int cnt) {
//	ans = max(ans, cnt);
//	for (int k = 0; k < 4; k++) {
//		int nx = x + dx[k];
//		int ny = y + dy[k];
//		if (nx >= 0 && nx < c&&ny >= 0 && ny < r) {
//			if (alpha[board[ny][nx] - 'A']==false) {
//				alpha[board[ny][nx] - 'A'] = true;
//				dfs(nx, ny,cnt+1);
//				alpha[board[ny][nx] - 'A'] = false;
//			}
//		}
//	}
//}
//int main()
//{
//
//	cin >> r >> c;
//
//	for (int i = 0; i < r; i++) {
//		cin >> board[i];
//	}
//	alpha[board[0][0] - 'A'] = true;
//	dfs(0, 0,1);
//	cout << ans;
//	return 0;
//}
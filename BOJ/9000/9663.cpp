#include <iostream>
#include <cstring>
using namespace std;

int dx[] = { -1,-1,0,1,1 };
int dy[] = { 0,1,1,1,0 };
int n;
int ans;
void copy(bool dst[15][15], const bool src[15][15]) {
	for (int i = 0; i < n; i++) {
		memcpy(dst[i],src[i],n*sizeof(bool));
	}
}
void track(int y,bool status[15][15]) {
	if (y == n) {
		ans += 1;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (status[y][x] == false) {
			status[y][x] = true;
			
			bool check[15][15];
			copy(check, status);
			for (int k = 0; k < 5; k++) {
				int nx = x;
				int ny = y;
				while (nx >= 0 && nx < n&&ny >= 0 && ny < n) {		
					check[ny][nx] = true;
					nx += dx[k];
					ny += dy[k];
				}
			}	
			track(y + 1, check);
		}
	}
}

int main()
{

	cin >> n;
	bool init[15][15] = { false };

	track(0, init);
	cout << ans;
	return 0;
}

//#include <iostream>
//using namespace std;
//bool a[15][15];
//int n;
//int ans = 0;
//bool check(int row, int col) {
//	// |
//	for (int i = 0; i<n; i++) {
//		if (i == row) continue;
//		if (a[i][col]) {
//			return false;
//		}
//	}
//	// 왼쪽 위 대각선
//	int x = row - 1;
//	int y = col - 1;
//	while (x >= 0 && y >= 0) {
//		if (a[x][y] == true) {
//			return false;
//		}
//		x -= 1;
//		y -= 1;
//	}
//	// /
//	x = row - 1;
//	y = col + 1;
//	while (x >= 0 && y < n) {
//		if (a[x][y] == true) {
//			return false;
//		}
//		x -= 1;
//		y += 1;
//	}
//	return true;
//}
//void calc(int row) {
//	if (row == n) {
//		ans += 1;
//	}
//	for (int col = 0; col<n; col++) {
//		a[row][col] = true;
//		if (check(row, col)) {
//			calc(row + 1);
//		}
//		a[row][col] = false;
//	}
//}
//int main() {
//	cin >> n;
//	calc(0);
//	cout << ans << '\n';
//	return 0;
//}

//#include <iostream>
//using namespace std;
//bool a[15][15];
//int n;
//bool check_col[15];
//bool check_dig[40];
//bool check_dig2[40];
//bool check(int row, int col) {
//	// |
//	if (check_col[col]) {
//		return false;
//	}
//	// 왼쪽 위 대각선
//	if (check_dig[row + col]) {
//		return false;
//	}
//	// /
//	if (check_dig2[row - col + n]) {
//		return false;
//	}
//	return true;
//}
//int calc(int row) {
//	if (row == n) {
//		// ans += 1;
//		return 1;
//	}
//	int cnt = 0;
//	for (int col = 0; col<n; col++) {
//		if (check(row, col)) {
//			check_dig[row + col] = true;
//			check_dig2[row - col + n] = true;
//			check_col[col] = true;
//			a[row][col] = true;
//			cnt += calc(row + 1);
//			check_dig[row + col] = false;
//			check_dig2[row - col + n] = false;
//			check_col[col] = false;
//			a[row][col] = false;
//		}
//	}
//	return cnt;
//}
//int main() {
//	cin >> n;
//	cout << calc(0) << '\n';
//	return 0;
//}
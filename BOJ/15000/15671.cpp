#include <iostream>
#define W 1
#define B -1
using namespace std;

int board[7][7];
bool visited[7][7];
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
void play(int x, int y, int d[2], int color) {
	//cout << x << ' ' << y << ' '<<color<<"-----------------\n";
	//1.다음번이 빈칸이면 종료
	//2.다음번이 다른색이면 계속탐색
	//3.다음번이 같은색인데 지금 다른색이면 지금색 바꿈
	int &now = board[y][x];
	int nx = x + d[0];
	int ny = y + d[1];
	if (nx >= 1 && nx < 7 && ny >= 1 && ny < 7) {
		int next = board[ny][nx];
		if (next == 0) {	//1
			return;
		}
		else {
			if (next != color) {	//2
				play(nx, ny, d, color);
				
			}
			if (next == color && now != color) {//3
				now = color;
				int px = x - d[0];
				int py = y - d[1];
				play(px, py, d, color);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	board[3][3] = board[4][4] = W;
	board[3][4] = board[4][3] = B;

	int turn = B;

	for (int tc = 0; tc < n; tc++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = turn;
		int d[8][2];
		for (int k = 0; k < 8; k++) {
			d[k][0] = dx[k];
			d[k][1] = dy[k];
			play(c, r, d[k], turn);
			
		}
		////확인출력
		//for (int i = 1; i < 7; i++) {
		//	for (int j = 1; j < 7; j++) {
		//		if (board[i][j] == 0) {
		//			cout << '.';
		//		}
		//		else if (board[i][j] == B) {
		//			cout << 'B';
		//		}
		//		else {
		//			cout << 'W';
		//		}
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		////
		turn *= -1;
	}

	int winner = 0;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (board[i][j] == 0) {
				cout << '.';
			}
			else if (board[i][j] == B) {
				cout << 'B';
				winner += B;
			}
			else {
				cout << 'W';
				winner += W;
			}
		}
		cout << '\n';
	}
	if (winner > 0) {
		cout << "White";
	}
	else {
		cout << "Black";
	}
	return 0;
}
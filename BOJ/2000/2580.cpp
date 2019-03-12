#include <iostream>
#include <deque>
using namespace std;

int sudoku[9][9];
bool c[9][10];
bool c2[9][10];
bool c3[9][10];
typedef pair<int, int> point;
deque<point> blank;

int square(int r, int c) {
	return (c / 3) * 3 + (r / 3);
}
bool check(point p, int num) {
	if (c[p.first][num]) {
		return false;
	}
	if (c2[p.second][num]) {
		return false;
	}
	if (c3[square(p.first, p.second)][num]) {
		return false;
	}
	return true;
}
void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
}
void track() {
	if (blank.empty()) {
		print();
		exit(0);
	}
	point now = blank.front();

	for (int i = 1; i <= 9; i++) {
		blank.pop_front();
		if (check(now, i)) {
			sudoku[now.first][now.second] = i;
			c[now.first][i] = true;
			c2[now.second][i] = true;
			c3[square(now.first, now.second)][i] = true;
			track();
			sudoku[now.first][now.second] = 0;
			c[now.first][i] = false;
			c2[now.second][i] = false;
			c3[square(now.first, now.second)][i] = false;			
		}
		blank.push_front(now);
		
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			int x = sudoku[i][j];
			if (x == 0) {
				blank.push_back(make_pair(i, j));
			}
			else {
				c[i][x] = true;
				c2[j][x] = true;
				c3[square(i, j)][x] = true;
			}
		}
	}

	track();

	return 0;
}
//#include <iostream>
//#include <deque>
//using namespace std;
//
//int sudoku[9][9];
//typedef pair<int, int> point;
//deque<point> blank;
//
//bool check(point p,int num) {
//	//가로
//	for (int i = 0; i < 9; i++) {
//		if (sudoku[p.first][i]==num) {
//			return false;
//		}
//	}
//	//세로
//	for (int i = 0; i < 9; i++) {
//		if (sudoku[i][p.second] == num) {
//			return false;
//		}
//	}
//	//사각형
//	int r = (p.first / 3)*3;
//	int c = (p.second / 3)*3;
//	for (int i = r; i < r+3; i++) {
//		for (int j = c; j < c+3; j++) {
//			if (sudoku[i][j] == num) {
//				return false;
//			}
//		}	
//	}
//	return true;
//}
//void print() {
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			cout << sudoku[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//void track() {
//	if (blank.empty()) {
//		print();
//		exit(0);
//	}
//	point now = blank.front();
//	
//	for (int i = 1; i <= 9; i++) {
//		blank.pop_front();
//		if (check(now, i)) {
//			sudoku[now.first][now.second] = i;
//			track();
//		}
//		sudoku[now.first][now.second] = 0;
//		blank.push_front(now);
//	}
//}
//int main()
//{
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			cin >> sudoku[i][j];
//			if (sudoku[i][j] == 0) {
//				blank.push_back(make_pair(i, j));
//			}
//		}
//	}
//
//	track();
//
//	return 0;
//}
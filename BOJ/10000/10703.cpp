#include <iostream>
#include <string>
using namespace std;

string photo[3000];
int pdata[3000][3000];
int meteo[3000];
int land[3000];
int rec[3000][3000];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int r, s;
	cin >> r >> s;

	for (int i = 0; i < r; i++) {
		cin >> photo[i];
		for (int j = 0; j < s; j++) {
			if (photo[i][j] == 'X') {
				pdata[i][j] = 1;
				meteo[j] = i + 1;
			}
			else if (photo[i][j] == '#') {
				pdata[i][j] = 2;
				rec[i][j] = 2;
				if (land[j] == 0) {
					land[j] = i;
				}
			}
		}
	}

	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < s; j++) {
	//		cout << pdata[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	int min = 3000;
	int h = 0;
	for (int i = 0; i < s; i++) {
		if (land[i] != 0 && meteo[i] != 0) {
			int d = land[i] - meteo[i];
			if (d < min) {
				min = d;
			}
			if (h < meteo[i]) {
				h = meteo[i];
			}
		}
	}
	//cout << min<< '\n';

	//for (int i = 0; i <r; i++) {
	//	for (int j = 0; j < s; j++) {
	//		cout << rec[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	for (int i = 0; i <h; i++) {
		for (int j = 0; j < s; j++) {
			if (rec[i + min][j] != 2) {
				rec[i + min][j] = pdata[i][j];
			}
		}
	}

	//for (int i = 0; i <r; i++) {
	//	for (int j = 0; j < s; j++) {
	//		cout << rec[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (rec[i][j] == 0) {
				cout << '.';
			}
			else if (rec[i][j] == 1) {
				cout << 'X';
			}
			else {
				cout << '#';
			}
		}
		cout << '\n';
	}

	return 0;
}
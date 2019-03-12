#include <bits/stdc++.h>
using namespace std;



int cube[25];
void cube_rotate(int a, int b, int c, int d, int e, int f, int g, int h) {
	int temp1 = cube[g];
	int temp2 = cube[h];
	cube[g] = cube[e]; cube[h] = cube[f]; cube[e] = cube[c]; cube[f] = cube[d]; cube[c] = cube[a]; cube[d] = cube[b]; cube[a] = temp1; cube[b] = temp2;
}
void FL() {
	cube_rotate(23, 24, 15, 16, 7, 8, 19, 20);
}
void FR() {
	cube_rotate(24, 23, 20, 19, 8, 7, 16, 15);
}
void BL() {
	cube_rotate(21, 22, 13, 14, 5, 6, 17, 18);
}
void BR() {
	cube_rotate(22, 21, 18, 17, 6, 5, 14, 13);
}
void LU() {
	cube_rotate(24, 22, 1, 3, 5, 7, 9, 11);
}
void LD() {
	cube_rotate(22, 24, 11, 9, 7, 5, 3, 1);

}
void RU() {
	cube_rotate(23, 21, 2, 4, 6, 8, 10, 12);

}
void RD() {
	cube_rotate(21, 23, 12, 10, 8, 6, 4, 2);

}
void UL() {
	cube_rotate(12, 11, 15, 13, 1, 2, 18, 20);

}
void UR() {
	cube_rotate(11, 12, 20, 18, 2, 1, 13, 15);

}
void DL() {
	cube_rotate(10, 9, 16, 14, 3, 4, 17, 19);

}
void DR() {
	cube_rotate(9, 10, 19, 17, 4, 3, 14, 16);

}
void(*fp[12])() = { FL,FR,BL,BR,LU,LD,RU,RD,UL,UR,DL,DR };
bool check() {
	return((cube[1] == cube[2] && cube[2] == cube[3] && cube[3] == cube[4]) && (cube[5] == cube[6] && cube[6] == cube[7] && cube[7] == cube[8]) && (cube[9] == cube[10] && cube[10] == cube[11] && cube[11] == cube[12]) && (cube[13] == cube[14] && cube[14] == cube[15] && cube[15] == cube[16]) && (cube[17] == cube[18] && cube[18] == cube[19] && cube[19] == cube[20]) && (cube[21] == cube[22] && cube[22] == cube[23] && cube[23] == cube[24]));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 24; ++i) {
		cin >> cube[i];
	}

	for (int i = 0; i < 12; i += 2) {
		fp[i]();
		if (check()) {
			cout << 1;
			return 0;
		}
		fp[i + 1]();
	}
	for (int i = 1; i < 12; i += 2) {
		fp[i]();
		if (check()) {
			cout << 1;
			return 0;
		}
		fp[i - 1]();
	}
	cout << 0;
	return 0;
}
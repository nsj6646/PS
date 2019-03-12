#include <cstdio>
#define ABS(x) (x)>=0?(x):-(x)
typedef struct point {
	int r, c;
}point;
point a[26];
int check[5][5];
int b_cnt = 0;
int isbingo(int r, int c) {	
	int ret = 0;
	int r_bingo = 1;
	for (int i = 0; i < 5; i++) {
		if (check[i][c] != 1) {
			r_bingo = 0;
			break;
		}
	}
	if (r_bingo == 1) {
		ret += 1;
	}

	int c_bingo = 1;
	for (int i = 0; i < 5; i++) {
		if (check[r][i] != 1) {
			c_bingo = 0;
			break;
		}
	}
	if (c_bingo == 1) {
		ret += 1;
	}

	if (r == c) {
		int cross1 = 1;
		for (int i = 0; i < 5; i++) {
			if (check[i][i] != 1) {
				cross1 = 0;
				break;
			}
		}
		if (cross1 == 1) {
			ret += 1;
		}
	}
	if (r + c == 4) {
		int cross2 = 1;
		for (int i = 0; i < 5; i++) {
			if (check[i][4 - i] != 1) {
				cross2 = 0;
				break;
			}
		}
		if (cross2 == 1) {
			ret += 1;
		}
	}
	return ret;
}
int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			scanf("%d", &x);
			a[x].r = i;
			a[x].c = j;
		}
	}

	for (int i = 1; i <= 25; i++) {
		int x;
		scanf("%d", &x);
		check[a[x].r][a[x].c] = 1;
		b_cnt += isbingo(a[x].r, a[x].c);
			
		if (b_cnt >= 3) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
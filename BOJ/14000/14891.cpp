//#include <cstdio>
//#include <cstring>
//
//int gear[5][8];
//int isrotate[5];
//void check(int from,int to) {
//	switch (from)
//	{
//	case 1:
//		if (gear[1][2] != gear[2][6]) {
//			isrotate[2] = isrotate[1] * -1;
//		}
//		break;
//	case 2:
//		if (to == 1) {
//			if (gear[2][6] != gear[1][2]) {
//				isrotate[1] = isrotate[2] * -1;
//			}
//		}
//		else {
//			if (gear[2][2] != gear[3][6]) {
//				isrotate[3] = isrotate[2] * -1;
//			}
//		}
//		break;
//	case 3:
//		if (to == 2) {
//			if (gear[3][6] != gear[2][2]) {
//				isrotate[2] = isrotate[3] * -1;
//			}
//		}
//		else {
//			if (gear[3][2] != gear[4][6]) {
//				isrotate[4] = isrotate[3] * -1;
//			}
//		}
//		break;
//	case 4:
//		if (gear[4][6] != gear[4][2]) {
//			isrotate[3] = isrotate[4] * -1;
//		}
//		break;
//	}
//}
//void rotate_r(int x) {
//	int temp = gear[x][7];
//	for (int i = 7; i >= 1; i--) {
//		gear[x][i] = gear[x][i - 1];
//	}
//	gear[x][0] = temp;
//}
//void rotate_l(int x) {
//	int temp = gear[x][0];
//	for (int i = 0; i < 7; i++) {
//		gear[x][i] = gear[x][i + 1];
//	}
//	gear[x][7] = temp;
//}
//void simulate(int x, int d) {
//	isrotate[x] = d;
//	switch (x)
//	{
//	case 1:
//		check(1,2);
//		check(2, 3);
//		check(3, 4);
//		break;
//	case 2:
//		check(2, 1);
//		check(2, 3);
//		check(3, 4);
//		break;
//	case 3:
//		check(3, 2);
//		check(3, 4);
//		check(2, 1);
//		break;
//	case 4:
//		check(4, 3);
//		check(3, 2);
//		check(2, 1);
//		break;
//	}
//	for (int i = 1; i <= 4; i++) {
//		if (isrotate[i] == 1) {
//			rotate_r(i);
//		}
//		else if (isrotate[i] == -1) {
//			rotate_l(i);
//		}
//	}
//
//}
//void printall() {
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 0; j < 8; j++) {
//			printf("%d ", gear[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//int calc() {
//	int ret = 0;
//	for (int i = 1; i <= 4; i++) {
//		ret += gear[i][0] << (i - 1);
//	}
//	return ret;
//}
//int main()
//{
//	int k;
//	scanf("%d", &k);
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 0; j < 8; j++) {
//			scanf("%1d", &gear[i][j]);
//		}
//	}
//
//
//	for (int i = 0; i < k; i++) {
//		memset(isrotate, 0, sizeof(int) * 5);
//		int gn, rd;
//		scanf("%d %d", &gn, &rd);
//		simulate(gn, rd);
//	}
//	printf("%d", calc());
//	return 0;
//}
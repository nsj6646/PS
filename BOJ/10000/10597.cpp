#include <cstdio>
#include <cstdlib>

#define LEN 451
#define NUM 51
int numCnt[NUM];
char input[LEN + 1];
char joke[LEN + 1];
int ans[NUM];
int len;
int n;


int strlen_(const char *str) {
	register int i = 0;
	for (i = 0; *(str + i) != 0; ++i);
	return i;
}

//bool strcmp_(const char *dst, const char *src) {
//	register int i = 0;
//	for (i = 0; *(dst+i)!=0&&*(src+i)!=0; ++i) {		
//		if (*(dst + i) != *(src + i)) {
//			return false;
//		}
//	}
//	return (*(dst + i) == 0 && *(src + i) == 0);
//}

void solve(int idx, int cnt) {
	if (cnt == n) {
		for (register int i = 0; i < cnt; ++i) {
			printf("%d ", ans[i]);
		}
		exit(0);

	}

	for (int i = 1; i <= n; ++i) {
		if (numCnt[i] != 0) continue;
		numCnt[i] = 1;
		ans[cnt] = i;
		if (i < 10) {
			if (input[idx] == i + '0') {
				joke[idx] = i + '0';
				solve(idx + 1, cnt + 1);
			}
		}
		else {
			if ((input[idx] == (i / 10) + '0') && (input[idx + 1] == (i % 10) + '0')) {
				joke[idx] = '0' + (i / 10);
				joke[idx + 1] = '0' + (i % 10);
				solve(idx + 2, cnt + 1);
			}
		}
		numCnt[i] = 0;
	}
}
int main()
{
	scanf("%s", input);
	len = strlen_(input);

	if (len > 9) {
		n = 9 + (len - 9) / 2;
	}
	else {
		n = len;
	}

	solve(0,0);

	return 0;
}
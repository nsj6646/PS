#include <cstdio>

int k, c;
bool coingame(int x, int y) {
	if ((x > y && y + k - x + 1 < x - 1) || (x < y && x + k - y < y - 1)) {
		return false;
	}
	else {
		return true;
	}
}
int main()
{

	scanf("%d %d", &k, &c);

	while (c--) {
		int m, n;
		scanf("%d %d", &m, &n);
		printf("%d\n", coingame(m, n) ? 1 : 0);
	}
	return 0;
}
/*
-영희가 큰 경우
	영희가 마지막에 앞면이 나오전 전의 상태 : (m-1,n)
	동수가 던질 수 있는 남은 횟수 : k-(m-1)
	동수가 얻을 수 있는 최대 점수 : n+k-(m-1)
	게임을 중단해야 할 조건 : m-1>n+k+2
	
	=>2m>n+k+2

-동수가 큰 경우
	동수가 마지막에 앞면이 나오전 전의 상태 : (m,n-1)
	영희가 던질 수 있는 남은 횟수 : k-n
	영희가 얻을 수 있는 최대 점수 : m+(k-n)
	게임을 중단해야 할 조건 : n-1>m+(k-n)

	=>2n>m+k+1
*/
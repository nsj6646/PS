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
-���� ū ���
	���� �������� �ո��� ������ ���� ���� : (m-1,n)
	������ ���� �� �ִ� ���� Ƚ�� : k-(m-1)
	������ ���� �� �ִ� �ִ� ���� : n+k-(m-1)
	������ �ߴ��ؾ� �� ���� : m-1>n+k+2
	
	=>2m>n+k+2

-������ ū ���
	������ �������� �ո��� ������ ���� ���� : (m,n-1)
	���� ���� �� �ִ� ���� Ƚ�� : k-n
	���� ���� �� �ִ� �ִ� ���� : m+(k-n)
	������ �ߴ��ؾ� �� ���� : n-1>m+(k-n)

	=>2n>m+k+1
*/
#include <cstdio>

bool d[2001][2001];
int gcd(int x, int y) {
	return x % y ? gcd(y, x%y) : y;
}
int main()
{
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	int ans = 0;
	for (int i = d1; i <= d2; i++) {//i번째 좌석
		for (int j = 1; j <= i; j++) {//i의 약수
			int g = gcd(i, j);
			if (!d[j / g][i / g]) {
				ans += 1;
				d[j / g][i / g] = true;
			}
		}
	}
	

	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//
//int d1, d2, v, c;
//bool p[21000001];
//
//int gcd(int x, int y) {
//	return x % y ? gcd(y, x%y) : y;
//}
//int main()
//{
//	scanf("%d %d", &d1, &d2);
//	
//	int i, j, t;
//
//	for (int i = d1; i <= d2; i++) {
//		for (int j = 1; j <= i; j++) {
//			v = gcd(i, j);
//			t = (i / v) * 10000 + j / v;
//
//			if (!p[t]) {
//				p[t] = true;
//				c++;
//			}
//			p[(i / v) * 10000 + j / v] = true;
//		}
//	}
//	printf("%d\n", c);
//	return 0;
//}
//#include <cstdio>
//
//int map[10000];
//
//int main()
//{
//	int D1, D2;
//	scanf("%d %d", &D1, &D2);
//	int i, j;
//
//	for (i = 1; i <= D2; i++)
//	{
//		for (j = 2 * i; j <= D2; j += i)
//		{
//			map[j] -= i + map[i];
//		}
//	}
//
//	for (i = 1; i <= D1 - 1; i++)
//	{
//		for (j = 2 * i; j <= D2; j += i)
//		{
//			if (D1 <= j && j <= D2)
//			{
//				map[j] += i + map[i];
//				break;
//			}
//
//		}
//	}
//
//	int ret = 0;
//	for (i = D1; i <= D2; i++)
//	{
//		ret += i + map[i];
//	}
//	printf("%d\n", ret);
//
//	return 0;
//}
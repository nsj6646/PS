#include <cstdio>

/*
A=Gx, B= Gy
LG =AB
LG=GGxy
L/G=xy
*/
bool isCoprime(int n, int m);
int main()
{
	int  g, l;
	scanf("%d %d", &g, &l);
	l /= g;
	int   a, b, x, y;
	
	x = 1;
	for (int i = 1; i*i <= l; i++) {
		if (l%i == 0) {
			if (isCoprime(i, l / i)) {
				x = i;
			}
		}
	}
	y = l / x;
	a = g * x; b = g * y;
	printf("%d %d", a, b);
	return 0;
}
bool isCoprime(int n, int m) {
	int d = 1;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0 && m%i == 0) {
			d = i;
			break;
		}
	}
	if (d == 1) {
		return true;
	}
	else {
		return false;
	}
}
/*
#include <cstdio>
#include <cmath>

int f(int x, int y)
{
	return x ? f(y%x, x) : y;
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	m /= n;
	for (i = sqrt(m + .5); m%i || f(i, m / i) > 1; i--);
	printf("%d %d", i * n, m / i * n);
}
*/
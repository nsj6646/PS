/*
boj 4673 : 셀프넘버
에라토스테네스의 체 활용하기
by nsj6646
*/
#include <cstdio>

int a[10001];
/*셀프넘버 함수*/
int d(int n) {
	int k = n;
	while (k > 0) {
		n += k % 10;
		k /= 10;
	}
	return n;
}
int main()
{
	for (int i = 1; i <= 10000; i++) {
		if (a[i] == 0) {
			/*아직 체크가 안된 숫자는 생성자*/
			for (int j = d(i); j <= 10000; j = d(j)) {
				/*생성자로부터 셀프넘버 생성해서 끝까지 체크하기*/
				a[j] = 1;
			}
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (a[i] == 0) {
			/*체크안된 숫자(생성자) 출력*/
			printf("%d\n", i);
		}
	}
	return 0;
}
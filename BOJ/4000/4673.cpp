/*
boj 4673 : �����ѹ�
�����佺�׳׽��� ü Ȱ���ϱ�
by nsj6646
*/
#include <cstdio>

int a[10001];
/*�����ѹ� �Լ�*/
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
			/*���� üũ�� �ȵ� ���ڴ� ������*/
			for (int j = d(i); j <= 10000; j = d(j)) {
				/*�����ڷκ��� �����ѹ� �����ؼ� ������ üũ�ϱ�*/
				a[j] = 1;
			}
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (a[i] == 0) {
			/*üũ�ȵ� ����(������) ���*/
			printf("%d\n", i);
		}
	}
	return 0;
}
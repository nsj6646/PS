#include <cstdio>
#include <cstring>
char a[10001];	//A입력
char b[10001];	//B입력
int c[10002];	//A+B의 결과 (배열의 크기가 1 큰이유는 마지막에 자리올림의 경우의 수 때문)

int calc(char x, char y) {		//문자+문자 = 숫자로 리턴해주는 함수
	int ret = (x - '0') + (y - '0');
	return ret;
}
int main()
{
	scanf("%s %s", a, b);	//문자열 입력
	
	//문자열의 길이 저장 : strlen함수의 시간복잡도는 O(N)이기 때문에 한번구한다음 저장해주는것이 훨씬 좋다.
	int n = strlen(a)-1;			//n : a의 길이-1 
	int m = strlen(b)-1;			//m : b의 길이-1
	int k = (n >= m ? n : m)+1;		//결과저장 배열의 인덱스 : a와 b중에서 긴 것 (+1을 해주는 이유는 마지막에 자리올림의 경우때문) 
	int l = k;						//c의 길이(k) 저장
	while (n >= 0 && m >= 0) {		//a나 b 둘중하나를 다 처리해줄때 까지
		c[k] += calc(a[n], b[m]);	//계산하고
		if (c[k] >= 10) {			//자리올림처리
			c[k - 1] += 1;
			c[k] -= 10;
		}
		k--; n--; m--;
	}

	//a나 b중 남은거 처리(a와 b가 자릿수가 다를수도 있기때문에)
	while (n >= 0) {
		c[k] += (a[n]-'0');
		if (c[k] >= 10) {
			c[k - 1] += 1;
			c[k] -= 10;
		}
		k--; n--;
	}
	while (m >= 0) {
		c[k] += (b[m] - '0');
		if (c[k] >= 10) {
			c[k - 1] += 1;
			c[k] -= 10;
		}
		k--; m--;
	}
	if (c[k] == 0) {		//마지막에 자리올림이 일어나지 않앗을경우에는 k++
		k++;
	}
	for (int i = k; i <= l; i++) {
		printf("%d", c[i]);
	}
	return 0;
}
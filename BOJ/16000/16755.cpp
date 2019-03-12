#include <cstdio>

char stk[5];
int top = -1;
int ans;
int main()
{
	char c;
	while ((c = getchar()) && c != '\n') {
		if (top==-1) {
			if (c == 'H') {
				stk[++top] = 'H';
			}
		}
		else {
			if (stk[top] == 'H'&&c == 'O') {
				stk[++top] = c;
			}
			else if (stk[top] == 'O'&&c == 'N') {
				stk[++top] = c;
			}
			else if (stk[top] == 'N'&&c == 'I') {
				stk[++top] = c;
			}
		}

		if (top==4) {
			top = -1;
			ans += 1;
		}
	}
	printf("%d",ans);
	return 0;
}
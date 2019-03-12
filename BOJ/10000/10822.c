//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char S[101];
//int main()
//{
//	int sum = 0;
//	int num;
//	scanf("%s", S);
//	char *token = strtok(S, ",");
//	
//	while (token != NULL) {
//		sum+=atoi(token);
//		printf("%s ", token);
//		token=strtok(NULL, ",");
//		
//	}
//	printf("%d", sum);
//	return 0;
//}
#include <stdio.h>

int main() {
	int num, sum = 0;
	while (scanf("%d,",&num) == 1) {
		sum += num;
	}
	printf("%d", sum);
}


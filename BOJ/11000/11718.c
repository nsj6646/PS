//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[101];
//	while (gets(str)) {
//		puts(str);
//	}
//	return 0;
//}

#include <stdio.h>
char str[101];
int main()
{
	while (scanf("%[^\n]\n",str)==1) {
		printf("%s\n", str);
	}
	return 0;
}

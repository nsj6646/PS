//#include <cstdio>
//#include <cstring>
//
//int main()
//{
//	char str[101];
//	while (fgets(str,101,stdin)) {
//		printf("%s", str);
//	}
//	return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	char str[101];
//	while(cin.getline(str,101)){
//		cout << str << "\n";
//	}
//
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str)) {
		cout << str << "\n";
	}

	return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int sum = 0;
	while(getline(cin, str, ',')){
		sum += stoi(str);
	}
	cout << sum;
	return 0;
}
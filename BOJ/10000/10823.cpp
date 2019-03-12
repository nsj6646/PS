#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string str;
	string line;
	while (cin >> line) {
		str += line;
	}
	istringstream sin(str);

	string number;
	int sum = 0;

	while (getline(sin, number, ',')) {
		sum += stoi(number);
	}
	cout << sum;
	return 0;
}
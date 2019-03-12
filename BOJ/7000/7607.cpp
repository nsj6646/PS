#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string input;
	
	while (getline(cin, input)) {
		if (input == "#") {
			break;
		}
		//print인지 아닌지
		if (input.substr(0, 5) == "print") {

			stringstream sin(input.substr(6));

		}
		else {
			stringstream sin(input.substr(6));
		}
		
	}
	return 0;
}
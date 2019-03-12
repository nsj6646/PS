#include <iostream>
using namespace std;

int main()
{

	int festival1[101] = { 0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10 };
	int festival2[65] = { 0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };
	int T;
	cin >> T;

	int ans = 0;
	for (int tc = 1; tc <= T; tc++) {
		int win1, win2;
		cin >> win1 >> win2;
		ans = (festival1[win1] + festival2[win2]) * 10000;
		cout << ans << '\n';
	}

	return 0;
}
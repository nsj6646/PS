#include <iostream>
using namespace std;

int main()
{
	int a[10], b[10];
	int suma = 0, sumb = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			suma += 3;
		}
		else if (a[i] < b[i]) {
			sumb += 3;
		}
		else {
			suma += 1;
			sumb += 1;
		}
	}
	cout << suma << ' ' << sumb << '\n';
	if (suma > sumb) {
		cout << 'A';
	}
	else if (suma < sumb) {
		cout << 'B';
	}
	else {
		for (int i = 9; i >= 0; i--) {
			if (a[i] > b[i]) {
				cout << 'A';
				return 0;
			}
			else if (a[i] < b[i]) {
				cout << 'B';
				return 0;
			}
		}
		cout << 'D';
	}
	return 0;
}
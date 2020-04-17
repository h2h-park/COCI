#include <iostream>
#include <string>

using namespace std;
string st;

int main(void) {
	int x = 1;
	cin >> st;
	for (auto c : st) {
		if (c == 'A' && x != 3) x = 3 - x;
		if (c == 'B' && x != 1) x = 5 - x;
		if (c == 'C' && x != 2) x = 4 - x;
	}
	cout << x << '\n';
	return 0;
}
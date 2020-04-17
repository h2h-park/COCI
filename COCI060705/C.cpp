#include <iostream>
#include <string>

using namespace std;
string a, b;
int n;
int fed = 0;

void nextint(int& x, char& c) {
	x = 0;
	for (;;) {
		scanf("%c", &c);
		if (c == ':' || c == ' ' || c == '\n') break;
		x *= 10;
		x += c - '0';
	}
}

int main(void) {
	int i, j;
	char c = 0;
	cin >> a >> b;
	if (a == "federer") fed = 1;
	if (b == "federer") fed = 2;
	for (cin >> n, scanf(" "); n--;) {
		int sta = 0, stb = 0;
		bool ne = false;
		bool valid = false;
		for (int st = 1;; st++) {
			nextint(i, c);
			nextint(j, c);
			valid = false;
			if (sta >= 2 || stb >= 2) {
				ne = true;
			}
			if (i == 6) {
				if (j <= 4) {
					if (fed == 2) ne = true;
					else {
						sta++;
						valid = true;
					}
				}
			}
			else if (i >= 7) {
				if ((st <= 2 && (j == 5 || j == 6)) || (st >= 3 && i - j == 2)) {
					if (fed == 2) ne = true;
					else {
						sta++;
						valid = true;
					}
				}
			}

			if (j == 6) {
				if (i <= 4) {
					if (fed == 1) ne = true;
					else {
						stb++;
						valid = true;
					}
				}
			}
			else if (j >= 7) {
				if ((st <= 2 && (i == 5 || i == 6)) || (st >= 3 && j - i == 2)) {
					if (fed == 1) ne = true;
					else {
						stb++;
						valid = true;
					}
				}
			}

			if (!valid) ne = true;
			if (c == '\n') {
				if (sta < 2 && stb < 2) ne = true;
				break;
			}
		}
		puts((ne) ? "ne" : "da");
	}
	return 0;
}
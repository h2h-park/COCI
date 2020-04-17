#include <stdio.h>

int g, w, d, l, s;

int next(void) {
	int ret = -1;
	char c;
	scanf(" %c", &c);
	if (c == '?') return ret;
	ret = c - '0';
	for (;;) {
		scanf("%c", &c);
		if (c == ' ' || c == '\n') break;
		ret *= 10;
		ret += c - '0';
	}
	return ret;
}

int main(void) {
	int n, i, j, k;
	for (scanf("%d", &n); n--;) {
		g = next();
		w = next();
		d = next();
		l = next();
		s = next();
		
		for (i = 0; i <= 100; i++) {
			if (w != -1) i = w;
			for (j = 0; j <= 100; j++) {
				if (d != -1) j = d;
				if (i + j > 100) break;
				for (k = 0; k <= 100; k++) {
					if (l != -1) k = l;
					if (i + j + k > 100) break;

					int g1 = i + j + k;
					int s1 = 3 * i + j;

					if ((g1 == g || g == -1) && (s1 == s || s == -1)) {
						printf("%d %d %d %d %d\n", g1, i, j, k, s1);
						break;
					}
					if (l != -1) break;
				}
				if (d != -1) break;
			}
			if (w != -1) break;
		}
	}
	return false;
}
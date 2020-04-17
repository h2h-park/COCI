#include <stdio.h>

int n, a, b;

int euclid(int p, int q) {
	return (p % q) ? euclid(q, p % q) : q;
}

int main(void) {
	scanf("%d %d", &n, &a);
	for (--n; n--;) {
		scanf("%d", &b);
		int g = euclid(a, b);
		printf("%d/%d\n", a / g, b / g);
	}
	return false;
}
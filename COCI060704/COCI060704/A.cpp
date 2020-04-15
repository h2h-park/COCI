#include <stdio.h>

int n, w, h;

int main(void) {
	int t;
	for (scanf("%d %d %d", &n, &w, &h); n--; ){
		scanf("%d", &t);
		puts((t * t <= w * w + h * h) ? "DA" : "NE");
	}
	return false;
}
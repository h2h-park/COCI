#include <stdio.h>
#define MAX 60

char ch[MAX][MAX];

int main(void) {
	int i, j, k, l;
	int r, c, zr, zc;
	scanf("%d %d %d %d", &r, &c, &zr, &zc);
	for (i = 1; i <= r; i++) {
		scanf("%s", &ch[i][1]);
	}
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= zr; j++) {
			for (k = 1; k <= c; k++) {
				for (l = 1; l <= zc; l++) printf("%c", ch[i][k]);
			}
			puts("");
		}
	}
	return false;
}
#include <stdio.h>
#define MAX 210

int n, cnt;
int num[MAX], dy[MAX][MAX];

int mx(int a, int b) {
	return (a > b) ? a : b;
}

int dp(int x, int* A) {
	int i, j, L;

	for (i = 1; i < n; i++) {
		dy[i][i] = A[i];
	}

	for (L = 2; L < n; L++) {
		for (i = 1; i < n; i++) {
			j = i + L - 1;
			if (j >= n) break;
			dy[i][j] = mx(A[j] - dy[i][j - 1], A[i] - dy[i + 1][j]);
		}
	}
	return x - dy[1][n - 1];
}

int main(void) {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		num[i] &= 1;
		num[i + n] = num[i];
	}
	for (i = 1; i <= n; i++) {
		if (dp(num[i], num + i) > 0) cnt++;
	}
	printf("%d\n", cnt);
	return false;
}
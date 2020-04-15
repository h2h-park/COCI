#include <stdio.h>
#define MAX 10010
#define ll long long

ll dy[2][MAX], mod = 1e9+7;
int n, m;

int main(void) {
	int i, j;
	scanf("%d %d", &n, &m);
	dy[1][0] = 1;
	for (i = 2; i <= n; i++) {
		dy[i & 1][0] = 1;
		for (j = 1; j <= m; j++) {
			dy[i & 1][j] = dy[i & 1][j - 1] + dy[!(i & 1)][j];
			if (j >= i) dy[i & 1][j] += mod - dy[!(i & 1)][j - i];
			dy[i & 1][j] %= mod;
		}
	}
	printf("%lld\n", dy[n & 1][m] % mod);
	return false;
}
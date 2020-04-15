#include <stdio.h>
#define MAX (1<<15) + 10

int tree[MAX], n;

void dfs(int x) {
	printf("%d ", tree[x]);
	if (x >= (1 << (n - 1))) return;
	dfs(x * 2);
	dfs(x * 2 + 1);
}

int main(void) {
	int i, j;
	scanf("%d", &n);
	tree[1] = 1;
	for (i = 2; i <= n; i++) {
		for (j = i - 1; j >= 1; j--) {
			for (int k = (1 << (j - 1)); k < (1 << j); k++) {
				tree[k + (1 << (j - 1))] = tree[k] << 1;
				tree[k + (1 << j)] = tree[k] << 1;
			}
		}
 		for (j = 2; j <= (1 << (i-2)); j <<= 1) {
			for (int k = j; k < j * 3 / 2; k++) tree[k]++;
		}
		for (j = (1 << (i - 1)) + (1 << (i-2)); j < (1 << i); j++) tree[j]++;
	}
	dfs(1);
	return false;
}
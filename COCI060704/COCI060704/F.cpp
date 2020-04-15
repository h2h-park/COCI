#include <stdio.h>
#include <algorithm>
#define MAX 200010

struct data {
	int A, B, i;
};
int n, m;
data stu[MAX];

int tree[MAX];
int input[MAX][3];

void update(int k, int x) {
	tree[x] = k;
	for (; x != 1; x >>= 1) {
		if (tree[x] <= tree[x >> 1]) break;
		tree[x >> 1] = tree[x];
	}
}

int main(void) {
	int i, j;
	char c;
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf(" %c", &c);
		if (c == 'D') {
			scanf("%d %d", &stu[++n].A, &stu[n].B);
			input[i][1] = stu[n].A, input[i][2] = stu[n].B;
			stu[n].i = n;
		} else {
			scanf("%d", &j);
			input[i][1] = j;
		}
	}
	std::sort(stu + 1, stu + n + 1, [](const data& a, const data& b) {
		return (a.B != b.B) ? a.B < b.B : a.A < b.A;
		});
	for (i = 1; i <= n; i++) stu[i].B = i;
	std::sort(stu + 1, stu + n + 1, [](const data& a, const data& b) {
		return a.i < b.i;
		});

	int term = 1, dep = 0;
	for (; term < n; term <<= 1, dep++);
	term--;
	for (i = 1; i <= m; i++) {
		if (input[i][0] == 0) {
			update(stu[i].B, term + stu[i].A);
		}
		else {
			int x = 1, X, Y;
			int p = stu[i].B;
			for (i = 0; i < dep; i++) {
				X = x * (1 << (dep - i));
				Y = x * (1 << (dep - i)) + (1 << (dep - i - 1)) - 1;
				if (X <= x && x <= Y) {

				}
				X = Y + 1;
				Y = (x + 1) * (1 << (dep - i)) - 1;
				if (X <= x && x <= Y) {
					x = x * 2 + 1;
					continue;
				}

				puts("NE");
				break;
			}
		}
	}
	return false;
}
#include <stdio.h>
#define MAX 1100

int n, m, inf = 1e9;
char ch[MAX][MAX];
int dy[2][MAX];

int min(int a, int b) { return (a > b) ? b : a; }

int main(void) {
    int i, j, k, t = 0;
    int mn = inf;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s", &ch[i]);
    for (i = 0; i < (1 << m); i++) dy[1][i] = inf;
    dy[1][0] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < (1 << m); k++) {
                dy[t][k] = inf;
                if (k & (1 << j)) {
                    if (ch[i][j] == '#')
                        dy[t][k] = min(dy[1 - t][k], dy[1 - t][k ^ (1 << j)] + 1);
                } else {
                    dy[t][k] = min(dy[1 - t][k], dy[1 - t][k ^ (1 << j)]);
                    if (ch[i][j] == '#') {
                        if (j == 0 || (k & (1 << (j - 1))) || ch[i][j - 1] == '.')
                            dy[t][k]++;
                    }
                }

                if (i == n && j == m - 1) {
                    mn = min(mn, dy[t][k]);
                }
            }
            t = 1 - t;
        }
    }
    printf("%d\n", mn);
    return false;
}
#include <stdio.h>
#include <algorithm>
#define MAX 200010

struct data {
    int A, B, i;
};
int n, m;
data stu[MAX];

int term = 1;
int tree[1 << 19];
int input[MAX][3], ord[MAX];

void update(int k, int x) {
    tree[x] = k;
    for (; x != 1; x >>= 1) {
        if (tree[x] <= tree[x >> 1]) break;
        tree[x >> 1] = tree[x];
    }
}

int find(int x, int to, int L, int R, int v) {
    if (to >= R || L > term + n || tree[x] < v) {
        return -1;
    }

    if (L == R) {
        return L - term;
    }
    int mid = (L + R) / 2;
    int t;
    t = find(x * 2, to, L, mid, v);
    if (t != -1) return t;
    return find(x * 2 + 1, to, mid + 1, R, v);
}

int main(void) {
    int i, j;
    char c;
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf(" %c", &c);
        if (c == 'D') {
            ++n;
            scanf("%d %d", &stu[n].A, &stu[n].B);
            input[i][1] = stu[n].A, input[i][2] = stu[n].B;
            stu[n].i = n;
        }
        else {
            scanf("%d", &j);
            input[i][1] = j;
            input[i][0] = 1;
        }
    }
    std::sort(stu + 1, stu + n + 1, [](const data& a, const data& b) {
        return (a.B != b.B) ? a.B < b.B : a.A < b.A;
        });
    for (i = 1; i <= n; i++) {
        stu[i].B = i;
    }
    std::sort(stu + 1, stu + n + 1, [](const data& a, const data& b) {
        return a.i < b.i;
        });

    for (i = 1; i <= n; i++) {
        ord[stu[i].B] = i;
    }

    for (; term < n; term <<= 1);
    term--;
    for (i = 1, j = 0; i <= m; i++) {
        if (input[i][0] == 0) {
            j++;
            update(stu[j].A, term + stu[j].B);
        }
        else {
            int t = find(1, term + stu[input[i][1]].B, term + 1, term * 2 + 1, stu[input[i][1]].A);
            if (t == -1) puts("NE");
            else printf("%d\n", ord[t]);
        }
    }
    return false;
}
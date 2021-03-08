#include <stdio.h>
#define MAX 665000
#define MAXN 10000000
#define ll long long

ll a, b, c, d;
ll p[MAX], pc;
bool isnp[MAXN];

bool divisible() {
    int i, cnt1, cnt2;
    for (i = 1; i <= pc; i++) {
        int P = p[i];
        cnt1 = 0, cnt2 = 0;
        while ((a-1) / P < b / P) {
            cnt1 += (b / P) - (a - 1) / P;
            P *= p[i];
        }
        P = p[i];
        while ((c - 1) / P < d / P) {
            cnt2 += (d / P) - (c - 1) / P;
            P *= p[i];
        }
        if (cnt2 < cnt1) return false;
    }
    return true;
}

int main(void) {
    int T;
    int i, j;
    for (i = 2; i <= MAXN; i++) {
        if (isnp[i]) continue;
        p[++pc] = i;
        if (i > 3162) continue;
        for (j = i * i; j <= MAXN; j += i) isnp[j] = true;
    }
    for (scanf("%d", &T); T--;) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        puts(divisible() ? "DA" : "NE");
    }
    return false;
}
#include <stdio.h>

#include <algorithm>
#include <stack>
#define MAX 110
int n, put = 4, rhand = 2;
int lr[MAX], cpy[MAX], arr[MAX];
int print[100010];
std::stack<int> st[2];

int main(void) {
    int i, j, cnt = 0;
    scanf("%d", &n);
    st[0].push(n + 1);
    for (i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        cpy[i] = arr[i];
    }
    std::sort(cpy + 1, cpy + n + 1);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cpy[j] == arr[i]) {
                arr[i] = j;
                cpy[j] = -1;
                break;
            }
        }
    }
    for (i = n; i >= 1; i--) st[0].push(arr[i]);
    int l;  // left = 0, right = 1
    for (i = n, j = n; i >= 1; i--) {
        l = lr[i];
        while (!st[l].empty() && st[l].top() != i) {
            int t = st[l].top();

            print[++cnt] = 0 + 0 + l;
            print[++cnt] = put + 0 + (1 - l);

            st[1 - l].push(t);
            lr[t] = 1 - lr[t];
            st[l].pop();
        }
        print[++cnt] = 0 + rhand + l;
        st[l].pop();

        while (st[0].top() != i + 1) {
            int t = st[0].top();
            print[++cnt] = 0 + 0;
            print[++cnt] = put + 0 + 1;

            st[1].push(t);
            lr[t] = 1 - lr[t];
            st[0].pop();
        }
        print[++cnt] = put + rhand;
        st[0].push(i);
    }
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; i++) {
        if (print[i] <= 3)
            printf("UZMI ");
        else {
            printf("STAVI ");
            print[i] -= 4;
        }
        if (print[i] <= 1)
            printf("L ");
        else {
            printf("D ");
            print[i] -= 2;
        }
        puts(print[i] ? "D" : "L");
    }
    return false;
}
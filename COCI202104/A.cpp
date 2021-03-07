#include <stdio.h>
#define MAX 110

int n, m;
bool check[MAX];

int main(void) {
    int a, b;
    for (scanf("%d", &n);n--;){
        scanf("%d", &a);
        check[a] = true;
    }
    int cnt = 0;
    for (scanf("%d", &m);m--;) {
        bool flag = false;
        for (scanf("%d", &a);a--;){
            scanf("%d", &b);
            if (check[b]) flag = true;
        }
        if (!flag) cnt++;
    }
    
    printf("%d\n", cnt);
    return false;
}
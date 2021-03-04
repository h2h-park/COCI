#include <stdio.h>
#include <stack>
#define MAX 100010

int a[MAX];
std::stack<int> st;

int main(void) {
    int n, i, cnt = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    st.push(0);
    for (i = 1; i <= n; i++) {
        while (st.top() > a[i]) {
            cnt++;
            st.pop();
        }
        if (st.top() < a[i]) st.push(a[i]);
    }
    while (!st.empty()){
        st.pop();
        cnt++;
    }
    printf("%d\n", cnt - 1);
    return false;
}
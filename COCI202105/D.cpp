#include <stdio.h>

#include <algorithm>
#include <stack>
#define MAX 1000010

struct pt {
    double x, y;
};

pt pts[MAX];
pt itv[MAX];
double p[MAX], h;
int n;

int greedy(void) {
    int ret = 0;

    std::sort(itv + 1, itv + n / 2,
              [](const pt& a, const pt& b) { return a.y < b.y; });

    pt now = {0, -1e10};
    for (int i = 1; i < n / 2; i++) {
        if (now.y < itv[i].x) {
            ret++;
            now = itv[i];
        }
    }
    return ret;
}

double ccw(pt a, pt b, pt c) {
    pt cb = {c.x - b.x, c.y - b.y};
    pt ba = {b.x - a.x, b.y - a.y};
    return cb.x * ba.y - cb.y * ba.x;
}

void getpoint(void) {
    int i, j = 0;
    std::stack<pt> st;
    st.push(pts[2]);
    for (i = 3; i < n; i++) {
        pt top;
        while (st.size() >= 2) {
            top = st.top();
            st.pop();
            if (ccw(st.top(), top, pts[i]) >= 0) {
                st.push(top);
                break;
            }
        }

        top = st.top();
        if (i & 1) {
            p[++j] =
                (top.x - pts[i].x) * (h - top.y) / (top.y - pts[i].y) + top.x;
        }
        st.push(pts[i]);
    }
}

int main(void) {
    int i;
    scanf("%d %lf", &n, &h);
    for (i = 1; i <= n; i++) scanf("%lf %lf", &pts[i].x, &pts[i].y);

    getpoint();
    for (i = 1; i < n / 2; i++) itv[i].x = p[i];
    std::reverse(pts + 1, pts + n + 1);
    for (i = 1; i <= n; i++) pts[i].x *= (-1);
    getpoint();
    for (i = 1; i < n / 2; i++) itv[i].y = p[n / 2 - i] * (-1);

    printf("%d\n", greedy());
    return false;
}
#include <stdio.h>
#include <queue>
#define MAX 2010

struct data {
    int x, y, px, py, c;
    bool operator < (const data& a) const {
        return this->c > a.c;
    }
};

std::priority_queue<data> pq;
int n, m, sx, sy, ex, ey;
char map[MAX][MAX];
int from[MAX][MAX]; // 1 - from up, 2 - from down, 3 - from left, 4 - from right
int dis[MAX][MAX];

int dir(data d) {
    if (d.px == 0 && d.py == 0) return 5;
    if (d.x == d.px) return (d.y < d.py) ? 4 : 3;
    return (d.x < d.px) ? 2 : 1;
}

int D(int N, char c) {
    if (c == '.') return 1;
    if (c == 'o') return 0;
    return ("v^><"[N - 1] == c) ? 0 : 1;
}

int main(void) {
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%s", &map[i][1]);
        for (j = 1; j <= m; j++) {
            if (map[i][j] == 'o') sx = i, sy = j;
            else if (map[i][j] == 'x') ex = i, ey = j;
            dis[i][j] = 1e9;
        }
    }
    dis[sx][sy] = 0;
    pq.push({ sx, sy, 0, 0, 0 });
    while (!pq.empty()) {
        data now = pq.top();
        pq.pop();
        if (from[now.x][now.y]) continue;
        from[now.x][now.y] = dir(now);
        if (now.x == ex && now.y == ey) {
            printf("%d\n", now.c);
            break;
        }

        for (i = 0; i < 4; i++) {
            int x1 = now.x + "2101"[i] - '1', y1 = now.y + "1210"[i] - '1';
            if (from[x1][y1]) continue;
            if (x1 < 1 || y1 < 1 || x1 > n || y1 > m) continue;
            int d = D(dir({ x1, y1, now.x, now.y, 0 }), map[now.x][now.y]);
            if (dis[x1][y1] > dis[now.x][now.y] + d) {
                dis[x1][y1] = dis[now.x][now.y] + d;
                pq.push({ x1, y1, now.x, now.y, dis[x1][y1] });
            }
        }
    }
    while (ex != sx || ey != sy) {
        int x1 = ex + "0211"[from[ex][ey] - 1] - '1', y1 = ey + "1102"[from[ex][ey] - 1] - '1';
        if (x1 != sx || y1 != sy) map[x1][y1] = "v^><"[from[ex][ey] - 1];
        ex = x1, ey = y1;
    }
    for (i = 1; i <= n; i++) printf("%s\n", &map[i][1]);
    return false;
}
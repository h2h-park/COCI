#include <iostream>
#include <string>
#include <vector>
#define MAX 100010

using namespace std;

int n;
string st;
int u[2], to_u[2];
vector<int> gr[2][MAX];
vector<int> vec[MAX];
bool from[2][MAX];
int path[MAX], pc;
bool flag;

void reachable(int sw, int par, int now) {
    from[sw][now] = true;
    for (int chd : gr[sw][now]) {
        if (par == chd) continue;
        reachable(sw, now, chd);
    }
}

bool esc(int sw) {  // sw is escaping from 1 - sw
    int i;
    int a, b;
    a = pc / 2, b = pc / 2 + 1;
    if (sw == 1) a += 2;
    a = path[a], b = path[b];
    for (i = 0; i < gr[sw][a].size(); i++) {
        if (gr[sw][a][i] == b) {
            gr[sw][a].erase(gr[sw][a].begin() + i);
            break;
        }
    }
    reachable(sw, 0, u[sw]);
    reachable(1 - sw, 0, u[1 - sw]);

    for (i = 1; i <= n; i++) {
        if (from[sw][i] > 0 && from[1 - sw][i] == 0) {
            for (int chd : gr[sw][i]) {
                if (from[1 - sw][chd]) continue;
                return false;
            }
        }
    }
    return true;
}

void print(bool flag, int k) {
    string player[2] = { "Paula\n", "Marin\n" };
    if (flag) cout << player[k];
    else cout << "Magenta\n";
}

void get_path(int par, int now, int des) {
    path[++pc] = now;
    if (now == des) {
        flag = true;
        return;
    }
    for (int chd : vec[now]) {
        if (par == chd) continue;
        get_path(now, chd, des);
        if (flag) return;
    }
    path[pc--] = 0;
}

bool cantmov(int sw) {
    if (gr[sw][u[sw]].size() == 0) return true;
    if (gr[sw][u[sw]].size() == 1 && gr[sw][u[sw]][0] == u[1 - sw] && sw == 0)
        return true;
    return false;
}

int main(void) {
    int i, a, b;
    cin >> n >> u[0] >> u[1];
    for (i = 1; i < n; i++) {
        cin >> a >> b >> st;
        if (st == "magenta") {
            gr[0][a].push_back(b);
            gr[1][a].push_back(b);
            gr[0][b].push_back(a);
            gr[1][b].push_back(a);
        }
        else if (st == "plava") {
            gr[0][a].push_back(b);
            gr[0][b].push_back(a);
        }
        else {
            gr[1][a].push_back(b);
            gr[1][b].push_back(a);
        }

        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    get_path(0, u[0], u[1]);
    if (cantmov(0)) {
        cout << "Marin\n";
        return false;
    }
    if (cantmov(1)) {
        cout << "Paula\n";
        return false;
    }
    if (pc & 1) {
        print(esc(1), 0);
    } else {
        print(esc(0), 1);
    }
    return false;
}
#include <iostream>
#include <math.h>
#define MAX 1010
#define ll long long

int n, C[MAX][MAX];
ll x[MAX];

using namespace std;

int main(void) {
    int i, j;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (i = 1; i <= n; i++) cin >> x[i];
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if ((int)(log2((double)x[i]) / 4) == (int)(log2((double)x[j]) / 4)) C[i][j] = 1;
            else if ((int)(log2((double)x[i]) / 16) == (int)(log2((double)x[j]) / 16)) C[i][j] = 2;
            else C[i][j] = 3;
        }
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j < i; j++) cout << C[j][i] << ' ';
        cout << '\n';
    }
    return false;
}
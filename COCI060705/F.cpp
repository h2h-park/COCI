#include <stdio.h>
#include <vector>
#include <string.h>
#define HMAX 1000010
#define MAX 200010

int n, mod = 1000007;
char ch[MAX];
std::vector<int> hash[HMAX];

bool check(int l) {
	int i, h = 0, pw = 1;
	for (i = 0; i < mod; i++) hash[i].clear();

	for (i = 1; i <= l; i++) {
		h *= 17;
		h += ch[i] - 'a' + 1;
		h %= mod;
		
		pw *= 17;
		pw %= mod;
	}
	hash[h].push_back(0);
	for (i = 2; i <= n - l + 1; i++) {
		h *= 17;
		h += (mod - pw) * (ch[i - 1] - 'a' + 1);
		h += ch[i + l - 1] - 'a' + 1;
		h %= mod;

		for (auto j : hash[h]) {
			for (int k = 0; k < l; k++) {
				if (ch[i + k] != ch[j + k]) break;
				if (k == l - 1) return true;
			}
		}

		hash[h].push_back(i);
	}
	return false;
}

int main(void) {
	scanf("%d", &n);
	scanf("%s", &ch[1]);
	int f = 1, l = n - 1, mid, ans = 0;
	for (; f <= l;) {
		mid = (f + l) / 2;
		if (check(mid)) {
			ans = mid;
			f = mid + 1;
		}
		else l = mid - 1;
	}
	printf("%d\n", ans);
	return false;
}
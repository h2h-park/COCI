#include <stdio.h>

class Trie {
public:
    int x;
    bool isleaf = true;
    bool nina = false;
    bool emil = false;
    Trie* next[30];

    void insert(char* c, int who) {
        if (*c == '\0') {
            if (who == 1) nina = true;
            if (who == 2) emil = true;
        }
        else {
            isleaf = false;
            int idx = *c - 'a' + 1;
            if (next[idx] == NULL) next[idx] = new Trie();
            next[idx]->insert(c + 1, who);
        }
    }
    Trie* find(char* c, int who) {
        if (*c == '\0') return this;
        int idx = *c - 'a' + 1;
        if (next[idx] == NULL) return NULL;  // not exist
        return next[idx]->find(c + 1, who);
    }
};
char ch[200010];

bool dp(Trie* now, int dep) {
    bool ret, isleaf = now->isleaf;
    int i;
    ret = dep & 1;
    if (isleaf){
        return (ret) ? now->nina : (!now->emil);
    }
    if (ret) {
        for (i = 1; i <= 26; i++) {
            if (now->next[i] == NULL) continue;
            ret &= dp(now->next[i], dep + 1);
        }
    }
    else {
        for (i = 1; i <= 26; i++) {
            if (now->next[i] == NULL) continue;
            ret |= dp(now->next[i], dep + 1);
        }
    }
    return ret;
}

int main(void) {
    int n, i;
    Trie* root = new Trie();
    for (scanf("%d", &n); n--;) {
        scanf(" %s", &ch);
        root->insert(ch, 1);
    }
    for (scanf("%d", &n); n--;) {
        scanf(" %s", &ch);
        root->insert(ch, 2);
    }
    puts(dp(root, 0) ? "Nina" : "Emilija");
    return false;
}
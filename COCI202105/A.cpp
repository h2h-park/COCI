#include <iostream>
#include <string>
#include <set>

using namespace std;
string st, subst;
set<string> S;

int main(void){
    int sz = 0;
    cin >> st;
    sz = st.size();
    for (int i = 0; i < sz; i++) {
        if (st[i] >= '0' && st[i] <='9') {
            subst = st[i];
            for (++i; i < sz; i++) {
                if (!(st[i] >= '0' && st[i] <='9')) break;
                subst += st[i];
            }
            S.insert(subst);
        }
    }
    cout << S.size() << endl;
    return false;
}
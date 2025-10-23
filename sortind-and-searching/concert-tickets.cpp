#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int tik, k; cin >> tik >> k;
    vector<int> custom(k);
    multiset<int> tckets;
 
    for (int i=0; i<tik; i++) {
        int v; cin >> v;
        tckets.insert(v);
    }
    for (int i=0; i<k; i++) cin >> custom[i];
 
    for (auto e:custom) {
        auto ans = tckets.upper_bound(e);
        if (ans != tckets.begin()) {
            ans--;
            cout << *ans << "\n";
            tckets.erase(ans);
        }
        else cout << "-1\n";
    }
 
 
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
unordered_map<string, int> rep;
vector<string> ans_s;
 
int permutation(string s, vector<bool> vis, string p="") {
    if ((int)p.size() == (int)s.size()) {
        if (rep[p]) {
            return 0;
        }
        rep[p] = 1;
        ans_s.push_back(p);
        return 1;
    }
 
    int cont = 0;
 
    for (int i=0; i<(int)s.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            p.push_back(s[i]);
            cont += permutation(s, vis, p);
            p.pop_back();
            vis[i] = 0;
        }
    }
 
    return cont;
 
}
 
int main() {
 
    string s; cin >> s;
    int t = s.size();
    vector<bool> vis(t, 0);
 
    sort(s.begin(), s.end());
 
    int ans = permutation(s, vis);
    cout << ans << "\n";
 
    for (auto e:ans_s) {
        cout << e << "\n";
    }
 
    return 0;
}
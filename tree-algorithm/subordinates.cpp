#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> tree;
vector<int> sub;
 
void dfs(int curr) {
 
 
    for (auto e:tree[curr]) {
        dfs(e);
        sub[curr] += sub[e];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    tree.resize(n);
    sub.assign(n, 1);
 
    for (int i=1; i<n; i++) {
        int a; cin >> a;
        a--;
        tree[a].push_back(i);
    }
 
    dfs(0);
 
    for (auto e:sub) cout << e-1 << " ";
    cout << "\n";
 
    return 0;
}
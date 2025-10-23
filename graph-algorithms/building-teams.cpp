#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> teams;
vector<bool> vis;
 
bool dfs(int curr, int cl) {
    vis[curr] = 1;
    teams[curr] = cl;
 
    bool ans = 1;
 
    for (auto &e:graph[curr]) {
        if (!vis[e]) {
            vis[e] = 1;
            if (teams[curr] == 1) {
                ans = dfs(e, 2);
            }
            if (teams[curr] == 2) {
                ans = dfs(e, 1);
            }
        }
        if (teams[e] == teams[curr]) ans=0;
    }
    return ans;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
 
    int n, k; cin >> n >> k;
    graph.resize(n); teams.resize(n); vis.assign(n, 0);
 
    for (int i=0; i<k; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    teams[0] = 1;
 
    bool ans = 1;
    
    for (int i=0; i<n; i++) {
        if (!vis[i]) ans = dfs(i, 1);
        if (!ans) break;
    }
 
    if (!ans) cout << "IMPOSSIBLE\n";
    else {
        for (auto e:teams) cout << e << " ";
        cout << "\n";
    }
 
    return 0;
}
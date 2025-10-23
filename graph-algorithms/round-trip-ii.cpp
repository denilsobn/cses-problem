#include <iostream>
#include <vector>
#include <algorithm>
 
#define IOS cin.tie(0)->ios_base::sync_with_stdio(false);
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> parent;
vector<char> vis;
int b_cycle = -1, e_cycle = -1;
 
bool dfs(int v) {
    vis[v] = 1;
 
    for (auto& e:graph[v]) {
        if (vis[e] == 0) {
            parent[e] = v;
            if (dfs(e)) return 1;
        }
        else if(vis[e] == 1) {
            b_cycle = v;
            e_cycle = e;
            return 1;
        }
    }
 
    vis[v] = 2;
    return 0;
}
 
vector<int> cycle() {
    int curr = b_cycle;
    vector<int> s;
 
    while(curr != e_cycle) {
        s.push_back(curr);
        curr = parent[curr];
    }
 
    reverse(s.begin(), s.end());
 
    return s;
 
}
 
int main() {
    IOS
 
    int n, m;
    cin >> n >> m;
 
    graph.resize(n+1);
    parent.resize(n+1);
    vis.resize(n+1, 0);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                break;
            }
        }
    }
 
 
    if (b_cycle == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    vector<int> ans = cycle();
    cout << ans.size() + 2 << "\n";
    cout << e_cycle << " ";
    for (auto e:ans) {
        cout << e << " ";
    }
    cout << e_cycle << "\n";
 
    return  0;
}

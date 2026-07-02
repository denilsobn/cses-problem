#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
vector<int> vis;

void dfs(int v) {
    vis[v] = 1;

    for (auto& e : G[v]) {
        if (!vis[e]) {
            dfs(e);
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    vis.resize(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
} 
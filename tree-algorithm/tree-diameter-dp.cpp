// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dist;

int diametro = 0;

int dfs(int u, int p) {
    int m1 = 0, m2 = 0;
    for (auto& v : G[u]) {
        if (v != p) {
           int dist = dfs(v, u);
           
           if (dist > m1) {
               m2 = m1;
               m1 = dist;
           }
           else {
               m2 = max(m2, dist);
           }
        }
    }
    
    diametro = max(diametro, m1 + m2);
    dist[u] = max(dist[u], m1 + m2);
    
    return m1 + 1;
}

int main() {
    int n;
    cin >> n;
    G.resize(n+1);
    dist.resize(n+1, 0);
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << dist[i] << " ";

    cout << "\n";
    
    cout << diametro << "\n";
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
 
using namespace std;
 
vector<vector<int>> g;
 
int bfs(int n, int f) {
    vector<int> vis(n+1, 0);
    vector<int> dist(n+1, 0);
 
    queue<int> fila;
    fila.push(f);
    vis[f] = 1;
 
    int best = 0, best_p = 0;
 
    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();
 
        for (auto e : g[curr]) {
            if (!vis[e]) {
                vis[e] = 1;
                dist[e] = dist[curr] + 1;
                if (dist[e] >= best) {
                    best = dist[e];
                    best_p = e;
                }
                fila.push(e);
            }
        }
    }
 
    return best_p;
 
}
 
pair<int, vector<int>> path(int n, int f) {
    vector<int> vis(n+1, 0);
    vector<int> dist(n+1, 0);
 
    queue<int> fila;
    fila.push(f);
    vis[f] = 1;
 
    int best = 0, best_p = 0;
 
    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();
 
        for (auto e : g[curr]) {
            if (!vis[e]) {
                vis[e] = 1;
                dist[e] = dist[curr] + 1;
                if (dist[e] >= best) {
                    best = dist[e];
                    best_p = e;
                }
                fila.push(e);
            }
        }
    }
 
    return {best_p, dist};
 
}
 
int main() {
    int n;
    cin >> n;
    g.resize(n+1);
 
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    int fa = bfs(n, 1);
 
    pair<int, vector<int>> d1 = path(n, fa);
    pair<int, vector<int>> d2 = path(n, d1.first);
 
    for (int i = 1; i <= n; i++) {
        cout << max(d1.second[i], d2.second[i]) << " "; 
    }
 
    return 0;
}
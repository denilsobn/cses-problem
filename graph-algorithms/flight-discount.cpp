#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define pii pair<int, long long>
#define tii tuple<long long, int, int>
#define INF 1e18

using namespace std;

vector<vector<pii>> g;
vector<vector<long long>> dist;

void dijkstra() {
    priority_queue<tii, vector<tii>, greater<tii>> p;
    p.push({0, 0, 0});

    while(!p.empty()) {
        auto[d, v, c] = p.top(); p.pop();

        if (d > dist[v][c]) continue;

        for (auto[u, w] : g[v]) {
            if (dist[u][c] > d + w) { // posso ter usado ou nao o cupom
                dist[u][c] = d + w;
                p.push({d + w, u, c});
            }
            
            // nao usei o cupom mas dist com o cupom usado é maior
            
            if (c == 0 && dist[u][1] > d + w / 2) {
                dist[u][1] = d + w / 2;
                p.push({d + w / 2, u, 1});
            }
        }

    }


}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    dist.assign(n, vector<long long>(2));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
    }

    for(int i = 0; i < n; i++) dist[i][0] = dist[i][1] = INF;

    dist[0][0] = 0;
    dist[0][1] = 0;

    dijkstra();

    cout << dist[n-1][1] << "\n";

    return 0;
}
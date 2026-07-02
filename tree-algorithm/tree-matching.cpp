#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> parent, leaf;

void bfs(int v, int n) {
    vector<bool> vis(n+1, 0);
    vis[v] = 1;
    queue<int>fila;
    fila.push(v);
    while(!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        bool filho = 0;

        for (auto& e : G[curr]) {
            if (!vis[e]) {
                filho = 1;
                vis[e] = 1;
                parent[e] = curr;
                fila.push(e);
            }
        }

        if (!filho) leaf.push_back(curr);

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    G.resize(n+1);
    parent.resize(n+1);

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(1, n);

    queue<int> fila;

    for (auto& e : leaf) {
        fila.push(e);
    }

    int cont = 0;

    while(!fila.empty()) {

    }

    cout << cont << "\n";

    return 0;
}

// G[1] = {1, 2}
// G[2] = {1, 3}
// G[3] = {2}
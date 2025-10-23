#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<int> d;
vector<vector<int>> g;
 
void topological(int n) {
    queue<int> p;
    vector<int> seq;
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) p.push(i);
    }
    
    while(!p.empty()) {
        int curr = p.front();
        p.pop();
        seq.push_back(curr);
        
        for (auto& e:g[curr]) {
            d[e]--;
            
            if (d[e] == 0) p.push(e);
        }
    }
    
    if ((int)seq.size() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    for (auto& e:seq) {
        cout << e << " ";
    }
    
    cout << "\n";
    
}
 
int main() {
    
    int n, k;
    cin >> n >> k;
    d.assign(n+1, 0);
    g.resize(n+1);
    
    while(k--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        d[b]++;
    }
    
    topological(n);
 
    return 0;
}
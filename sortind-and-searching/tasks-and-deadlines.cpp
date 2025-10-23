#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t; cin >> t;
    vector<pair<int, int>> task;
 
    while (t--) {
        int a, b; cin >> a >> b;
        task.push_back({a, b});
    }
 
    sort(task.begin(), task.end());
 
    ll ans = 0, time=0;
 
    for (auto e:task) {
        time += e.first;
        ans += e.second - time;
    }
 
    cout << ans << "\n";
 
    return 0;
}
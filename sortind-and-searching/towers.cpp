#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    vector<int> nums(n);
    multiset<int> towers;
 
    for (int i=0; i<n; i++) cin >> nums[i];
 
    int ans = 0;
 
    for (auto e:nums) {
        auto t_up = towers.upper_bound(e);
        if (t_up == towers.end()) {
            ans++;
            towers.insert(e);
        }
        else {
            towers.erase(t_up);
            towers.insert(e);
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    ll n, k; cin >> n >> k;
 
    unordered_map<ll, ll> appear;
    appear[0] = 1;
    ll sum=0, ans=0;
 
    for (int i=0; i<n; i++) {
        ll num; cin >> num;
        sum += num;
        ans += appear[sum-k];
        appear[sum]++;
    }
 
    cout << ans << "\n";
 
    return 0;
}
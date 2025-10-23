#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    vector<ll> nums(n);
    ll sum=0;
 
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
 
    ll best = INT_MAX;
 
    for (int i=0; i<(1 << n); i++) {
        ll side=0;
        for (int k=0; k<n; k++) {
            if (i & (1 << k)) side += nums[k];
        }
 
        best = min(best, abs(sum-(2*side)));
 
    }
 
    cout << best << "\n";
 
    return 0;
}
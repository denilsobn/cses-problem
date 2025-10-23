#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<ll> nums;
map<ll, ll> heap;
 
ll cont(int n, int k) {
    ll ans = 0, sum=0;
    heap[0] = 1;
 
    for (int i=0; i<n; i++) {
        sum += nums[i];
        if (heap[sum-k]) ans+=heap[sum-k];
        heap[sum] += 1;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; ll k; cin >> n >> k;
    nums.resize(n);
    
    for (int i=0; i<n; i++) cin >> nums[i];
 
    cout << cont(n, k) << "\n";
 
    return 0;
}
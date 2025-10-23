#include <iostream>
#include <vector>
#include <algorithm>
 
#define ll long long
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    ll k, sum;
    cin >> k >> sum;
 
    vector<ll> nums(k), dp(sum+1, INF);
 
    for (int i=0; i<k; i++) cin >> nums[i];
 
    dp[0] = 0;
 
    sort(nums.begin(), nums.end());
 
    for (int i=1; i<=sum; i++) {
        for (int t=0; t<k && nums[t] <= i; t++) {
            if (dp[i-nums[t]] == INF) continue; //não tem como fazer essa soma
            dp[i] = min(dp[i], dp[i - nums[t]] + 1); // vejo qual a menor soma possível
        }
    }
 
    if (dp[sum] == INF) cout << "-1\n";
    else cout << dp[sum] << "\n";
 
    return 0;
}
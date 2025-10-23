#include <iostream>
#include <vector>
 
using namespace std;
 
const int MOD = 1e9+7;
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    int n, sum;
 
    cin >> n >> sum;
 
    vector<int> nums(n), dp(sum+1, 0);
 
    for (int i=0; i<n; i++) cin >> nums[i];
 
    dp[0] = 1;
 
    for (int i=0; i<n; i++) {
        for (int k=0; k<=sum; k++) {
            if (k - nums[i] < 0) continue;
            dp[k] = (dp[k] + dp[k - nums[i]]) % MOD;
        }
    }
 
    cout << dp[sum] << '\n';
 
    return 0;
}
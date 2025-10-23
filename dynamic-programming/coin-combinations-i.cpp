#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 1e6+10, MOD = 1e9+7;
 
long long dp[MAXN];
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    int n, sum;
 
    cin >> n >> sum;
 
    vector<int> nums(n);
 
    for (int i=0; i<n; i++) cin >> nums[i];
 
    dp[0] = 1;
 
    sort(nums.begin(), nums.end());
 
    for (int i=1; i<=sum; i++) {
        for (int k=0; k<n && nums[k] <= i; k++) {
            dp[i] = (dp[i] + dp[i-nums[k]]) % MOD;
        }
    }
 
    cout << dp[sum] << "\n";
 
 
    return 0;
}
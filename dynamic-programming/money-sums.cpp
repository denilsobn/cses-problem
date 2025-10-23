#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAXN = 100*1000;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> nums(n);
 
    int k = 0;
 
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        k += nums[i];
    }
 
    vector<int> dp(MAXN+7, 0);
 
    dp[0] = 1;
 
    for (int i=0; i<n; i++) {
        for (int j=k; j>=nums[i]; j--) {
            if (dp[j-nums[i]]) {
                dp[j] = 1;
            }
        }
    }
 
    int ans = 0;
 
    for (int i=1; i<=k; i++) {
        if (dp[i]) ans++;
    }
    cout << ans << "\n";
    for (int i=1; i<=k; i++) {
        if (dp[i]) cout << i << " ";
    }
 
    return 0;
}
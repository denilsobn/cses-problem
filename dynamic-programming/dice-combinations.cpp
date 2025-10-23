#include <iostream>
#include <vector>
 
#define int long long
 
using namespace std;
 
const int MAXN = 1e6+10, MOD = 1e9+7;
 
vector<int> dice = {1, 2, 3, 4, 5, 6};
 
int dp[MAXN];
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int sum;
    cin >> sum;
 
    dp[0] = 1;
 
    //como posso evitar recalcular?
 
    for (int i=1; i<=sum; i++) {
        for (int k=1; k<=6 && k <= i; k++) {
            dp[i] = (dp[i] + dp[i-k]) % MOD;
        }
    }
 
    cout << dp[sum] << "\n";
 
    return 0;
}
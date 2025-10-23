#include <iostream>
#include <string>
 
using namespace std;
 
const int MAXN = 1e6+10, INF = 1e9;;
 
int dp[MAXN];
bool vis[MAXN];
 
int removing(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
 
    if (vis[n]) return dp[n];
 
    vis[n] = 1;
    
    string num = to_string(n);
 
    for (int i=0; i<(int)num.size(); i++) {
        if (num[i] == '0') continue;
        int value = num[i] - '0';
        dp[n] = min(dp[n], removing(n - value)+1);
    }
 
    return dp[n];
 
}
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    for (int i=0; i<=MAXN; i++) dp[i] = INF;
 
    cout << removing(n)-1 << "\n";
 
    return 0;
}
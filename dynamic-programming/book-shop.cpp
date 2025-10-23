#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<int> pages(n), price(n);
 
    for (int i=0; i<n; i++) cin >> price[i];
    for (int i=0; i<n; i++) cin >> pages[i];
 
    vector<int> dp(k+1, 0);
 
    for (int i=0; i<n; i++) {
        for (int p=k; p>=price[i]; p--) {
            dp[p] = max(dp[p], pages[i] + dp[p-price[i]]);
        }
    }
 
    // 0 0 0 5 5 5 5 5 5 5
    // 0 0 0 5 5 5 5 12 12 12
    // 0 0 0 5 
    // começa pelo final para saber qual a melhor soma
 
    cout << dp[k] << "\n";
 
    return 0;
}
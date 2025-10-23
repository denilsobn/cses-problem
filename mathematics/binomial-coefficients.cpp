#include <iostream>
#include <vector>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9+7, MAXN = 1e6;
 
int fat[MAXN+2], inv[MAXN+2];
 
int power(int base, int exp) {
    int ans = 1;
 
    while (exp > 0) {
        if (exp & 1) ans = (base * ans) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}
 
void precompute() {
    fat[0] = fat[1] = 1;
 
    for (int i = 2; i <= MAXN; i++) {
        fat[i] = (fat[i-1] % MOD * i % MOD) % MOD;
    }
 
    inv[MAXN] = power(fat[MAXN], MOD-2);
 
    for (int i = MAXN - 1; i >= 0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}
 
int bc(int n, int k) {
    return (fat[n] % MOD * inv[k] % MOD * inv[n-k] % MOD) % MOD;
}
 
 
int32_t main() {
    int q;
    cin >> q;
 
    precompute();
 
    while (q > 0) {
        int n, k;
        cin >> n >> k;
        cout << bc(n, k) << "\n";
        q--;
    }
 
    return 0;
}
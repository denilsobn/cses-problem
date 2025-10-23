#include <iostream>
#define ll long long
 
using namespace std;
 
ll const MOD = 1e9+7, MAXN = 2*(1e6);
 
ll fat[MAXN+1], inv[MAXN+1];
 
ll power(ll base, ll exp) {
    ll result = 1;
 
    while(exp) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
 
    return result;
}
 
void precompute() {
    fat[1] = fat[0] = 1;
    for (ll i = 2; i <= MAXN; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
    }
 
    inv[MAXN] = power(fat[MAXN], MOD-2);
 
    for (ll i = MAXN - 1; i >= 0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}
 
ll solution(ll a, ll b) {
    ll ans = (fat[a+b-1] * inv[b]) % MOD;
    ans = (ans * inv[a-1]) % MOD;
 
    return ans;
 
}
 
int main() {
    ll a, b;
    cin >> a >> b;
 
    precompute();
 
    cout << solution(a, b) << "\n";
 
    return 0;
}
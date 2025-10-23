#include <iostream>
#include <unordered_map>
 
#define ll long long
 
using namespace std;
 
const ll MAXN = 1e6, MOD = 1e9+7;
 
ll fat[MAXN+1], inv[MAXN+1];
 
ll power(ll base, ll exp) {
    ll result = 1;
 
    while(exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
 
    return result;
}
 
ll factorial(ll n) {
    fat[1] = 1;
    for (int i = 2; i <= n; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
    }
    return fat[n];
}
 
ll ans(ll size, unordered_map<char, ll>& freq) {
    ll result = factorial(size);
 
    for (auto& e:freq) {
        if (e.second > 1) {
            result = (result * power(fat[e.second], MOD-2)) % MOD;
        }
    }
 
    return result;
}
 
int main() {
    string word;
    cin >> word;
 
    unordered_map<char, ll> freq;
 
    for (auto& e:word) {
        freq[e]++;
    }
 
    ll t = word.size();
 
    cout << ans(t, freq) << "\n";
 
    return 0;
}
#include <iostream>
 
using namespace std;
 
const long long MOD = 1e9+7;
 
long long exp(int a, int b) {
    if (b == 0) return 1;
    long long base = exp(a, b/2);
    long long ans = (base * base) % MOD;
    if(b % 2 == 1) ans = (ans * a) % MOD;
    return ans;
}
 
int main() {
    int k{0};
    cin >> k;
 
    while(k--) {
        int a, b;
        cin >> a >> b;
        cout << exp(a, b) << "\n";
    }
 
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
int cont(int n) {
    int div = 0;
    for (int i=1; i*i<=n; i++) {
        if (n%i == 0) {
            if (i == n/i) div++;
            else div += 2;
        }
    }
    return div;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int k; cin >> k;
    
    while (k--) {
        int n; cin >> n;
        cout << cont(n) << "\n";
    }
 
    return 0;
}
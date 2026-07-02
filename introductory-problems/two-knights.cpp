#include <bits/stdc++.h>

#define int long long

using namespace std;

int ans(int k) {
    

    int ans = ((k * k) * (k * k - 1)) / 2LL;

    int menor = (k - 3 + 1) * (k - 2 + 1);

    return ans - (menor * 4);

}

int32_t main() {

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        cout << ans(i) << "\n";
    }

    return 0;
}
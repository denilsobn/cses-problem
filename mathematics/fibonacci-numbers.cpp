#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

vector<vector<ll>> mult(const vector<vector<ll>>& m1, const vector<vector<ll>>& m2) {
    
    vector<vector<ll>> ans(m1.size(), vector<ll>(m2[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m1[0].size(); k++) {
                ans[i][j] = (ans[i][j] + ((m1[i][k] * m2[k][j]) % MOD)) % MOD;

            }
        }
    }

    return ans;

}

ll exp(ll n) {

    vector<vector<ll>> m = {{1, 1}, {1, 0}};
    vector<vector<ll>> res = {{1, 0}, {0, 1}}; // numero neutro na operação

    n--;

    while(n) {
        if (n & 1) res = mult(res, m);

        m = mult(m, m);

        n >>= 1;
    }

    res = mult(res, {{1}, {0}});

    return res[0][0] % MOD;

}

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << n << "\n";
        return 0;
    }

    cout << exp(n) << "\n";

    return 0;
}
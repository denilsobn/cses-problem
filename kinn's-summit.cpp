#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a, b;

    while(n--) {
        int k, q;
        cin >> k >> q;
        a.push_back(k);
        b.push_back(q);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mid_a = a[a.size()/2];
    int mid_b = b[b.size()/2];

    int result_a, result_b;

    result_a = min(abs(mid_a - a[0]), abs(mid_a - a.back()));
    result_b = min(abs(mid_b - b[0]), abs(mid_b - b.back()));

    int ans = max(result_a, result_b);

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;

    while(n--) {
        int k;
        cin >> k;
        if (k == 1) {
            int num;
            cin >> num;
            q.push(num);
        } else {
            cout << q.top() << "\n";
            q.pop();
        }
    }


    return 0;
}
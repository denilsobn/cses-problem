#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> nums(n);
    stack<pair<int, int>> smallest;
 
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }
 
    for (int i=0; i<n; i++) {
        
        while (!smallest.empty() && smallest.top().first >= nums[i]) {
            smallest.pop();
        }
 
        if (smallest.empty()) cout << "0 ";
        else cout << smallest.top().second+1 << " ";
        smallest.push({nums[i], i});
 
    }
 
    return 0;
}
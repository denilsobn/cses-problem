#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    
    
    while (n--) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            cout << "YES\n"; continue;
        }
        else if(a == 0 || b == 0) {
            cout << "NO\n"; continue;
        }
 
        if (a < b) swap(a, b);
        if (a - (b*2) > 0) {
            cout << "NO\n"; continue;
        }
 
        if ((a+b)%3 == 0) cout << "YES\n";
        else cout << "NO\n";
        
    }
 
 
}
 
/*
14 4
12 3
10 2
8 1
6 0 
*/
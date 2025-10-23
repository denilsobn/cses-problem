#include <iostream>
 
using namespace std;
 
void move(int n, int in=1, int t=2, int fi=3) {
    if (n == 1) {
        cout << in << " " << fi << "\n";
        return;
    }
 
    move(n-1, in, fi, t);
    cout << in << " " << fi << "\n";
    move(n-1, t, in, fi);
}
 
int cont(int n) {
    if (n == 0) return 1;
    int pot = 2;
    return pot * cont(n-1);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n;
    
    int ans = cont(n)-1;
 
    cout << ans << "\n";
 
    move(n, 1, 2, 3);
}
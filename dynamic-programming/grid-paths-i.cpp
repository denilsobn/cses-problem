#include <iostream>
#define ll long long
 
using namespace std;
 
const int MOD = 1e9+7, MAXN = 1e3+10;
 
char grid[MAXN][MAXN];
ll grid_p[MAXN][MAXN];
bool grid_v[MAXN][MAXN];
 
ll path(int l, int c) {
    if (l == 1 && c == 1) return 1;
 
    if (grid_v[l][c]) return grid_p[l][c];
 
    grid_v[l][c] = 1;
 
    if (l-1 >= 1 && grid[l-1][c] != '*') grid_p[l][c] = (grid_p[l][c] + path(l-1, c)) % MOD;
    if (c-1 >= 1 && grid[l][c-1] != '*') grid_p[l][c] = (grid_p[l][c] + path(l, c-1)) % MOD;
 
    return grid_p[l][c];
}
 
int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }
 
    if (grid[1][1] == '*') cout << "0\n";
    else if (grid[n][n] == '*') cout << "0\n";
    else cout << path(n, n) << "\n";
 
    return 0;
}
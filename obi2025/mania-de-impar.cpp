#include <iostream>

using namespace std;

int grid[110][110];
int times[110][110];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (grid[i][j] % 2 == grid[i][j+1] % 2) {
                times[i][j]++;
                times[i][j+1]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (grid[j][i] % 2 == grid[j+1][i] % 2) {
                times[j][i]++;
                times[j+1][i]++;
            }
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << times[i][j] << " ";
        }
        cout << "\n";
    }

    for (int k = 4; k >= 2; k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (times[i][j] == k) {
                    grid[i][j]++;
                    for (int l = 0; l < 4; l++) {
                        int n_a = i + dx[l];
                        int n_b = j + dy[l];
                        if (n_a >= 0 && n_b >= 0 && n_a < n && n_b < m) {
                            times[n_a][n_b]--;
                        }
                    }
                    times[i][j] = 0;
                }
            }
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << times[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
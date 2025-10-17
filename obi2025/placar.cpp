#include <bits/stdc++.h>

using namespace std;

int main() {
    int p;
    cin >> p;

    queue<int> p_gol;
    queue<int> c_gol;

    for (int i = 0; i < p; i++) {
        int num; cin >> num;
        p_gol.push(num);
    }

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int num; cin >> num;
        c_gol.push(num);
    }

    int a = 0, b = 0;

    while (!c_gol.empty() || !p_gol.empty()) {
        cout << a << " " << b << "\n";
        if (c_gol.empty()) {
            a++;
            p_gol.pop();
        }
        else if (p_gol.empty()) {
            b++;
            c_gol.pop();
        }
        else {
            if (p_gol.front() < c_gol.front()) {
                a++;
                p_gol.pop();
            } else {
                b++;
                c_gol.pop();
            }
        }
    }

    cout << a << " " << b << "\n";


    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {     
    string s;
    cin >> s;
    vector<pair<int, char>> rep;
 
    int t = s.size();
 
    sort(s.begin(), s.end());
 
    if (t%2 == 0) {
        char curr = s[0];
        int cont=1, poss=1;
        for (int i=1; i<t; i++) {
            if (s[i] == curr) cont++;
            else {
                rep.push_back({cont, curr});
                if (cont%2 >= 1) poss = 0;
                cont = 1;
                curr = s[i];
            }
        }
        rep.push_back({cont, curr});
 
        if (!poss) {
            cout << "NO SOLUTION\n";
            return 0;
        }
 
        string palidrome = "";
 
        for (auto e:rep) {
            for (int i=0; i<e.first/2; i++) {
                palidrome.push_back(e.second);
            }
        }
 
        cout << palidrome;
        sort(palidrome.rbegin(), palidrome.rend());
        cout << palidrome << "\n";
 
    }
    else {
        char curr = s[0], mid;
        int cont=1;
        for (int i=1; i<t; i++) {
            if (s[i] == curr) cont++;
            else {
                rep.push_back({cont, curr});
                cont = 1;
                curr = s[i];
            }
        }
        rep.push_back({cont, curr});
 
        int odd=0;
 
        for (auto e:rep) {
            if (e.first%2 >= 1) {
                odd++;
                mid = e.second;
            }
        }
 
        if (odd != 1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
 
        string palidrome = "";
 
        int mid_cont = 0;
 
        for (auto e:rep) {
            if (e.second == mid) {
                mid_cont = e.first;
                continue;
            }
 
            for (int i=0; i<e.first/2; i++) {
                palidrome.push_back(e.second);
            }
        }
 
        cout << palidrome;
        for (int i=0; i<mid_cont; i++) cout << mid;
        sort(palidrome.rbegin(), palidrome.rend());
        cout << palidrome << "\n";
 
    }
 
    return 0;
}
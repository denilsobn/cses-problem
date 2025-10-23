#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> schedule;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        schedule.push_back({b, a});
    }
    
    sort(schedule.begin(), schedule.end());
    
    int cont = 1;
    int curr = schedule[0].first;
    for (int i = 0; i < n-1; i++) {
        if (curr <= schedule[i+1].second) {
            cont++;
            curr = schedule[i+1].first;
        }
    }
    
    cout << cont << "\n";
    
}
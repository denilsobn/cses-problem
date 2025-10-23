#include <iostream>
#include <vector>
 
using namespace std;
 
vector<string> reverse(vector<string> res) {
    vector<string> ans;
 
    int t = (int) res.size() - 1;
 
    for (int i = 0; i <= t; i++) {
        ans.push_back(res[t-i]);
    }
 
    return ans;
}
 
vector<string> gray(int n, vector<string> a) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> res = gray(n-1, a);
 
    int i = 0;
 
    for (; i < (1 << n)/2; i++) {
        a.push_back("0"+res[i]);
    }
 
    int j = 0;
 
    vector<string> aux = reverse(res);
    
    for (; i < (1 << n); i++) {
        a.push_back("1"+aux[j]);
        j++;
    }
 
    return a;
 
}
 
// 00
// 01
// 11
// 10
 
int main() {
 
    cin.tie(0)->ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    vector<string> a;
 
    a = gray(n, a);
 
    for (auto& e:a) cout << e << "\n";
    
    return 0;
}
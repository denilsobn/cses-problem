#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
 
using namespace std;
 
bool possible(vector<ll>& nums, ll time, ll tot) {
    
    ll cont = 0;
    for (auto& e:nums) {
        cont += time/e;
        if (cont >= tot) return 1;
    }
    
    if (cont >= tot) return 1;
    return 0;
 
}
 
 
int main() {
     cin.tie(0)->ios_base::sync_with_stdio(false);
     
     int n;
     ll tot;
     cin >> n >> tot;
     
     vector<ll> nums(n);
     
     for (int i = 0; i < n; i++) {
         cin >> nums[i];
     }
     
     sort(nums.begin(), nums.end());
     
     ll l = 0, r = nums[0] * tot;
     
     while (l < r) {
         ll mid = (l + r) >> 1;
         if (!possible(nums, mid, tot)) {
             l = mid + 1;
         } else {
             r = mid;
         }
     }
     
     cout << l << "\n";
     
     return 0;
}

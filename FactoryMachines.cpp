#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    for(int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    long long left = 0;
    long long right = 1e18;
    while(left < right) {
        long long mid = left + (right - left)/2;
        long long products = 0;
        for(int i = 0; i < n; i++) {
            products += mid / machines[i];
            if(products >= t) break;
        }
        if(products >= t) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }    
    cout << left << endl;
    return 0;
}
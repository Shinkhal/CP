#include<bits/stdc++.h>
using namespace std;

int nthMagical(int n, int a, int b) {
    const int m = 1e9+7; 
    long long lcm = (1LL * a * b) / __gcd(a, b); 
    long long low = min(a, b), high = (long long)n * min(a, b);

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long count = mid / a + mid / b - mid / lcm; 

        if (count < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low % m;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = nthMagical(n, a, b);
    cout << ans;
    return 0;
}

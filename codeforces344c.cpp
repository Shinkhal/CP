#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll resistance(ll a, ll b) {
    if (a == 1 && b == 1) return 1;
    if (a == 0) return 0;
    if (a > b) {
        ll x = a / b;
        return x + resistance(a%b, b);
    } else {
        return b / a + resistance(b % a, a);
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = resistance(a, b);
    cout << ans << endl;
    return 0;
}

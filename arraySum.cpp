#include <bits/stdc++.h>
using namespace std;

int sum(int i, int arr[], int n) {
    if (i == n) return 0;
    return arr[i] + sum(i + 1, arr, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = sum(0, arr, n);

    cout << ans << endl;
    return 0;
}

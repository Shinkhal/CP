#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        adj[a][b]++;
    }
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    
    dp[1][0] = 1;
    
    for(int mask = 1; mask < (1 << n); mask++) {
        if(!(mask & 1)) continue;
        if((mask & (1 << (n-1))) && mask != ((1 << n) - 1)) continue;
        for(int last = 0; last < n; last++) {
            if(!(mask & (1 << last))) continue;
            int prev = mask ^ (1 << last);
            for(int prev_last = 0; prev_last < n; prev_last++) {
                if(!(prev & (1 << prev_last))) continue;
                if(adj[prev_last][last] == 0) continue;
                
                dp[mask][last] = (dp[mask][last] + 
                                 dp[prev][prev_last] * adj[prev_last][last]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n-1] << endl;
    
    return 0;
}

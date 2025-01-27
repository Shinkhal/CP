#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countDiceCombinations(int x) {
    vector<int> dp(x + 1, 0);
    
    dp[0] = 1;
    
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    return dp[x];
}

int main() {
    int x;
    cin >> x;
    
    cout << countDiceCombinations(x) << endl;
    
    return 0;
}

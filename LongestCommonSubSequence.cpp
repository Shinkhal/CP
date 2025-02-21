#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestPalindromeSubseq(const string& s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1; 
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2; 
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin,s);
    cout << "Length of Longest Palindromic Subsequence: " << longestPalindromeSubseq(s) << endl; // Output: 4
    return 0;
}
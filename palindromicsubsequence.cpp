#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

int countPalindromicSubsequences(string s){
	int n = s.size();

	vector<vector<int>>dp(n,vector<int>(n,0));

	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
    for(int len =2;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j = i+len -1;
            if(s[i]==s[j]){
                int left = i+1;
                int right = j-1;

                while (left <= right && s[left] != s[i]) {
                    left++;
                }
                    
                while (left <= right && s[right] != s[j]) {
                    right--;
                }
                if(left>right){
                    dp[i][j] = dp[i+1][j-1] * 2 + 2;
                }
                else if(left == right){
                    dp[i][j] = dp[i+1][j-1] * 2 + 1;
                }
                else{
                    dp[i][j] = dp[i+1][j-1] * 2 - dp[left+1][right-1];
                }
            }
            else{
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
            dp[i][j] = (dp[i][j] + mod)%mod;
        }
    }
    return max(1, dp[0][n-1]);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin,s);
    int ans = countPalindromicSubsequences(s);
    cout<<ans<<endl;

    return 0;
}

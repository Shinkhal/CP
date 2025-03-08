#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

int LongestIncreasingSubsequence(vector<int>&arr){
	int n = arr.size();
	
	vector<int>dp(n,1);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	return *max_element(dp.begin(),dp.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Insert your code here...
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    cout<<LongestIncreasingSubsequence(arr)<<endl;

    return 0;
}

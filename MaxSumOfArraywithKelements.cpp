#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN


int MaxElements(vector<int>&arr, int n, int k){
	int curr=0;
	int maxsum = minv;

	for(int i=0;i<k;i++){
		curr += arr[i];
	}

	for(int i=k;i<n;i++){
		curr+= arr[i]- arr[i-k];
		maxsum = max(curr,maxsum);
	}
	return maxsum;
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
    int k;
    cin>>k;

    int ans = MaxElements(arr,n,k);
    cout<<ans<<endl;

    return 0;
}

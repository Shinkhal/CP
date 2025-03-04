#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

vector<int> NextPermutation(vector<int>&arr){
	int n = arr.size();
	int idx = -1;

	for(int i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1]){
			idx =i;
			break;
		}
	}

	if(idx == -1){
		reverse(arr.begin(),arr.end());
		return arr;
	}

	for(int i=n-1;i>idx;i--){
		if(arr[i]>arr[idx]){
			swap(arr[i],arr[idx]);
			break;
		}
	}

	reverse(arr.begin()+idx+1,arr.end());
	return arr;
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

    vector<int>ans = NextPermutation(arr);

    for(auto it : ans){
    	cout<<it << " ";
    }
    cout<<endl;

    return 0;
}

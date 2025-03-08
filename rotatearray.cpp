#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN


// void rotate(vector<int>& arr, int k){
// 	int n= arr.size();
// 	k = k%n;

// 	reverse(arr.begin(), arr.end());
// 	reverse(arr.begin(), arr.begin()+k);
// 	reverse(arr.begin()+k, arr.end());

// }

void rotateArray(vector<int>& arr,int k){
    k = k%arr.size();

    rotate(arr.begin(),arr.end()-k,arr.end());
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

    rotateArray(arr,k);

    for (int num : arr) cout << num << " ";
    cout<<endl;

    return 0;
}

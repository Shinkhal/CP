#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0) return b;

    return gcd(b%a,a);
}

int findGcd(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int n= nums.size();
    int a = nums[0];
    int b = nums[n-1];
    return gcd(a,b);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = findGcd(nums);
    cout<<ans<<endl;
    return 0;
}
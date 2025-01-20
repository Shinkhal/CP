#include<bits/stdc++.h>
using namespace std;

int sum(int left,int arr[],int right){
    int mid = left +(right-left)/2;
    if(left==right){
        return arr[left];
    }
    int leftSum = sum(left,arr,mid);
    int rightSum = sum(mid+1,arr,right);
    return leftSum+rightSum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = sum(0,arr,n-1);
    cout<<ans;
    return 0;
}
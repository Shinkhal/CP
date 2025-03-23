#include <bits/stdc++.h>
using namespace std;

// int sum(int i, int arr[], int n) {
//     if (i == n) return 0;
//     return arr[i] + sum(i + 1, arr, n);
// }

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     int ans = sum(0, arr, n);

//     cout << ans << endl;
//     return 0;
// }

void func(vector<int> arr, int i,vector<int>& output,int val){
    if(i==arr.size())return;

    if(arr[i]==val){
        output.push_back(i);
        
    }
    func(arr,i+1,output,val);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val;
    cin>>val;
    vector<int>output;
    func(arr,0,output,val);

    for(int j: output){
        cout<<j<<endl;
    }
}

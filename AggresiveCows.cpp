#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isPossible(vector<int>& arr, int mid,int n, int k){
            int cow=1, last = arr[0];
            for(int i=1;i<n;i++){
                if(arr[i]-last>=mid){
                    cow++;
                    last = arr[i];
                }
                if(cow==k){
                    return true;
                }
            }
            return false;
        }


        int aggressiveCows(vector<int>& arr, int k){
            int n = arr.size();
            sort(arr.begin(),arr.end());
            int low = 0, high = arr[n-1]-arr[0];
            int ans=0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(isPossible(arr,mid,n,k)){
                    low = mid+1;
                    ans = mid;
                }
                else{
                    high = mid -1;
                }
            }
            return ans;
        }

};
int main(){
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
    }
    return 0;
}
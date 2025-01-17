#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> productExceptSelf(vector<int>& arr){
        int n = arr.size();
        vector<int> arr2;
        int mul =1;
        for(int i = 0; i < n; i++){
            mul = mul * arr[i];
        }
        for(int i = 0; i < n; i++){
            arr2.push_back(mul/arr[i]);
        }
        return arr2;
    }
};

int main(){
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
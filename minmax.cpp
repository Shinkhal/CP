#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinMax(int arr[], int n) {
        vector<int> ans;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] < minVal) minVal = arr[i];
            if (arr[i] > maxVal) maxVal = arr[i];
        }
        ans.push_back(minVal);
        ans.push_back(maxVal);
        return ans;
    }
};

int main() {
    int arr[] = {3, 1, 5, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution sb;
    vector<int> res = sb.findMinMax(arr, n);
    
    cout << "Min: " << res[0] << ", Max: " << res[1] << endl;
    return 0;
}

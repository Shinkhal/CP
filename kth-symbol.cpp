#include <bits/stdc++.h>
using namespace std;

int countLessEqual(vector<vector<int>>& arr, int mid, int n) {
    int count = 0;
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n) {
        if (arr[row][col] <= mid) {
            count += row + 1; 
            col++;        
        } else {
            row--; 
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>>& arr, int k) {
    int n = arr.size();
    int low = arr[0][0];        
    int high = arr[n - 1][n - 1]; 

    while (low < high) { 
        int mid = low + (high - low) / 2;
        int count = countLessEqual(arr, mid, n);

        if (count < k) {
            low = mid + 1; 
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> k;
    cout << kthSmallest(arr, k) << "\n";
    
    return 0;
}

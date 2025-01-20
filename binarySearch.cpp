#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 4, 5};
    int target = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int first_occ = -1, last_occ = -1; 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            first_occ = mid;
            high = mid - 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            last_occ = mid;
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "First occurrence: " << first_occ << endl;
    cout << "Last occurrence: " << last_occ << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;

int modPow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> primeIndex;
    int primeCount = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        for (int p = 2; p * p <= num; ++p) {
            if (num % p == 0) {
                if (primeIndex.find(p) == primeIndex.end()) {
                    primeIndex[p] = primeCount++;
                }
                while (num % p == 0) {
                    num /= p;
                }
            }
        }
        if (num > 1) {
            if (primeIndex.find(num) == primeIndex.end()) {
                primeIndex[num] = primeCount++;
            }
        }
    }
    vector<int> dp(1 << primeCount, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        int mask = 0;
        for (auto& [prime, index] : primeIndex) {
            int count = 0;
            while (num % prime == 0) {
                num /= prime;
                count++;
            }
            if (count % 2 == 1) {
                mask ^= (1 << index);
            }
        }
        vector<int> newDp = dp;
        for (int j = 0; j < (1 << primeCount); ++j) {
            newDp[j ^ mask] = (newDp[j ^ mask] + dp[j]) % MOD;
        }
        dp = newDp;
    }
    int result = 0;
    for (int i = 1; i < (1 << primeCount); ++i) {
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;

    return 0;
}
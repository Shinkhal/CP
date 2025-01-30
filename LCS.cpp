#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN



int lcs(string& s1, string& s2,int m,int n){
	if(n==0 || m==0)return 0;
	if(s1[m-1]==s2[n-1]){
		return 1 + lcs(s1,s2,m-1,n-1);
	}else{
		return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
	}

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    int ans = lcs(s1,s2,s1.size(),s2.size());
    cout<<ans<<endl;
    return 0;
}

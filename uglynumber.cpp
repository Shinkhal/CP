#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

ll lcm(ll a, ll b){
	return (a*b/gcd(a,b));
}

bool check(ll mid,ll n, ll a, ll b, ll c){
	ll p = (mid/a + mid/b + mid/c);
	ll q = (mid/lcm(a,b) + mid/lcm(b,c)+ mid/lcm(a,c));
	ll r = mid/lcm(a,lcm(b,c));
	ll count = p-q+r;
	if(count>=n)return true;

	return false;
}
int nthUgly(ll n, ll a, ll b, ll c){
	ll low = 1, high = 1e18, ans =0;
	while(low<=high){
		ll mid = low + (high -low)/2;
		if(check(mid,n,a,b,c)){
			ans = mid;
			high = mid -1;
		}
		else low = mid+1;
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Insert your code here...
    ll n, a,b,c;
    cin>>n >>a >> b>> c;
    int ans = nthUgly(n,a,b,c);
    cout<<ans<<endl;

    return 0;
}

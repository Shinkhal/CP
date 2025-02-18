#include <bits/stdc++.h>
using namespace std;

typedef long long ll
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN


pair<int, int> bfs(int start, vector<vector<int>> &adj, int n){
	
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0;i<n;i++){
    	int a,b;
    	cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    pair<int, int> first = bfs(1,adj,n);
    pair<int,int>second = bsf(first.first, adj,n);
    cout<<second.second<<endl;

    return 0;
}

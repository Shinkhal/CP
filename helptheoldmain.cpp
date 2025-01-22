#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int N,int n,int from,int to,int aux, int &moves, vector<int>& res){
	if(N==0)return;

	towerOfHanoi(N-1,n,from,aux,to,moves,res);
	moves ++;
	if(moves == n){
		res.push_back(from);
		res.push_back(to);
		return; 
	}
	towerOfHanoi(N-1,n,aux,to,from,moves,res);
}

vector<int> shiftPile(int N,int n){
	int moves =0;
	vector<int>res;
	towerOfHanoi(N,n,1,3,2,moves,res);
	return res;
}

int main(){
	int N,n;
	cin>>N>>n;
	vector<int>ans = shiftPile(N,n);
	cout<<ans[0]<<" "<<ans[1]<<endl;
}
//safe problem 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void flip(string& original, int idx){
	if(original[idx]=='0'){
		original[idx]='1';
	}else{
		original[idx]='0';
	}
}
void generate(string& original, int same, int i, vector<string>& ans){
	if(i == original.length()){
		if(same ==0){
			ans.push_back(original);
		}
		return;
	}
	if(same >0)
		generate(original,same-1,i+1,ans);
	flip(original,i);
	generate(original,same,i+1,ans);
	flip(original,i);
}
bool verify(string& s1,string& s2, int k){
	int same =0;
	for(int i=0;i<s1.length();i++){
		if(s1[i]==s2[i]){
			same++;
		}
	}
	return same==k;
}
vector<string> filter(vector<string>& allPoss, string curr, int same) {
	vector<string> tmp;
	for (int i = 0; i < allPoss.size(); i++) {
		if (verify(allPoss[i],curr,same)) {
			tmp.push_back(allPoss[i]);
		}
	}
	return tmp;
}

int main(){
	int n,m;
	cin>>n>>m;
	string s ;
	int c;
	cin>>s>>c;
	vector<string> allPoss;
	generate(s,c,0,allPoss);
	m--;
	while(m--){
		cin>>s>>c;
		allPoss= filter(allPoss,s,c);
	}
	cout<<allPoss.size();
	return 0;
}
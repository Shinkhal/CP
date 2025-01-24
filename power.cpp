#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
	if(b==0)return 1;
	if(b<0){
		a = 1/a;
	}
	int x = power(a,b/2);


	if(b%2==0){
		return x*x;
	}else{
		return x*a*x;
	}

}

int main(){
	int a,b;
	cin>>a>>b;
	int p = power(a,b);
	cout<<p<<endl;
	return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
	if(b==0)return 1;
	if(b<0){
		a = 1/a;
		b -=b;
	}

	int x = power(a,b/2);

	if(b%2==0){
		return x*x;
	}else{
		return x*a*x;
	}

}

double powerdouble(double a, int b) {
    if (b == 0) return 1.0;
    if (b < 0) {
        a = 1 / a;
        b = -b;
    }

    double d = powerdouble(a, b / 2);

    if (b % 2 == 0) {
        return d * d;
    } else {
        return d * d * a;
    }
}

int main(){
	int a,b,y;
	double x;
	cin>>a>>b;
	cin>>x;
	cin>>y;
	int p = power(a,b);
	double z = powerdouble(x,y);
	cout<<p<<" "<<z<<endl;
	
	return 0;
}
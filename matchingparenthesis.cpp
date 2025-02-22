#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

bool check(string& s){
	int n = s.size();
	stack<char>st;

	for(int i=0;i<n;i++){
		if(st.empty() || s[i]=='(' ||s[i]=='{' || s[i] == '[')st.push(s[i]);
		else{
			if(st.empty())return false;

				if(s[i]==')' && st.top()=='(')st.pop();
				else if(s[i]=='}' && st.top()=='{')st.pop();
				else if(s[i]==']' && st.top()=='[')st.pop();
				else return false;
		}
	}
	if(st.empty())return true;
	return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Insert your code here...
    string s;
    getline(cin,s);

    bool ans = check(s);

    if(ans){
    	cout<<"Valid"<<endl;
    }else{
    	cout<<"Invalid"<<endl;
    }

    return 0;
}

#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> s;
set<string>::iterator it;
string x;
int ans,n,i,a,b,c;
int main() {
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x; 
		char ch=x[0]; x.erase(0,1);
		if(ch=='+') s.insert(x);
		else s.erase(x);
	}    
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<endl;
	return 0;
}



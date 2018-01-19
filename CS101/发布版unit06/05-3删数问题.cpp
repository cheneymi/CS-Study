#include<iostream>
#include<string>
using namespace std;
string s;
int x,i,j;
int main(){
	cin>>s>>x;
	for(i=0;i<x;i++){
		for(j=0;j<s.size()-1;j++)
			if(s[j]>s[j+1]) break;
		s.erase(j,1);
	}
	cout<<s<<endl;
	return 0;
}




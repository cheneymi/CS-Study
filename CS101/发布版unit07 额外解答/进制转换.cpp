#include<iostream>
#include<string>
using namespace std;
int main() {
    int n,b;
    string s="";
    cin>>n>>b;
	while(n){
		int re=n%b; 
		char d;
		if(re<10) d='0'+re;
		else d='A'+re-10;
		s=d+s;
		n/=b;
	}
	cout<<s<<endl;
    return 0;
}

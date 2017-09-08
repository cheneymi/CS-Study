#include <iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=65&&s[i]<=90)
			cout<<char(s[i]+32);
		if(s[i]>=97&&s[i]<=122)
			cout<<char(s[i]-32);
	}
	cout<<endl;
	return 0;
}

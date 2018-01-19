#include<iostream>
#include<string> 
#include<sstream>
#include<string> 
#include<set> 
using namespace std;
int main() {	
	string a,b,word;
	getline(cin,a); getline(cin,b);
	a=a.substr(a.find(':')+2);
	b=b.substr(b.find(':')+2);
	set<string> x,y; 
	stringstream ss;
	ss<<a;
	while(ss>>word) x.insert(word);
	ss.clear();
	ss<<b;
	while(ss>>word) y.insert(word);
	set<string>::iterator it;
	int c=0;
	for(it=y.begin();it!=y.end();it++)	 
		if(x.count(*it)>0) c++;
	cout<<c<<'/'<<y.size()<<endl;		
	return 0;
}





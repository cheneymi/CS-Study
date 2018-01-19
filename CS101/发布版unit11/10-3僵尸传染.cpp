#include<iostream>
#include<string> 
#include<set> 
using namespace std;
int main() {
	set<string> s;  
	set<string>::iterator it;
	s.insert("zombie");
	int m;
	cin>>m;
	for(int i=0;i<m;i++) {
		string a,b;
		cin>>a>>b;	
		if(s.count(a)){
			if(!s.count(b)) s.insert(b);
		}else if(s.count(b)) s.insert(a);
	}
	cout<<s.size()<<endl;
	return 0;
}





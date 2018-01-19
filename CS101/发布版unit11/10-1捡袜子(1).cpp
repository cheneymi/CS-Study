#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> s;
int main() {
	int ans=0,n,i;
	cin>>n;
	for(i=0;i<n;i++){
		string x;
		cin>>x; 
		if(s.count(x)==0) s.insert(x);
		else{
			ans++;
			s.erase(x);
		} 			
	}    
	cout<<ans<<endl;
	return 0;
}


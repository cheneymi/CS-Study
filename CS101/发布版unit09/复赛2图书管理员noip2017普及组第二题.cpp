#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#define N 1005
using namespace std;
int n,q,book[N],i,j,l,m;
bool check(int x,int y){
	string a,b; 
	stringstream ss;
	ss<<x<<' '<<y; ss>>a>>b;
	int la=a.size(), lb=b.size();
	return la>=lb and a.substr(la-lb)==b;
}
int main(){
	cin>>n>>q;
	for(i=0;i<n;i++) cin>>book[i];
	sort(book,book+n);
	for(i=0;i<q;i++){
		cin>>l>>m;
		for(j=0;j<n;j++) 
			if(check(book[j],m)) break;
		if(j<n) cout<<book[j]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}

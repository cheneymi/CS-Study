#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
struct food{
	int s,t;
};
food f[N];
int cmp(const food& a,const food& b){
	return a.t<b.t;
}
int main(){	
int n,i,x,ans;
	cin>>n;	
	for(i=0;i<n;i++) cin>>f[i].s;
	for(i=0;i<n;i++) cin>>f[i].t;
	sort(f,f+n,cmp);
	x=f[0].t; ans=1;
	for(i=1;i<n;i++)
		if(f[i].s>=x) {
			ans++;
			x=f[i].t;
		}
	cout<<ans<<endl;	
	return 0;
}

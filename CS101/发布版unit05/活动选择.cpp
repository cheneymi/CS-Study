#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
struct movie{
	int s,t;
};
movie m[N];
int n,i,x,ans;
int cmp(const movie& a,const movie& b){
	return a.t<b.t;
}
int main(){
	cin>>n;	
	for(i=0;i<n;i++) cin>>m[i].s;
	for(i=0;i<n;i++) cin>>m[i].t;
	sort(m,m+n,cmp);
	x=m[0].t; ans=1;
	for(i=1;i<n;i++)
		if(m[i].s>x) {
			ans++;
			x=m[i].t;
		}
	cout<<ans<<endl;	
	return 0;
}

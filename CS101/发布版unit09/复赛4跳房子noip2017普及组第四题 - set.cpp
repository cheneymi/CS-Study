#include<iostream>
#include<set>
#define M 500005
using namespace std;
int n,d,k,f[M],x[M],s[M],ok[M];
int check(int g){
	int dmax=d+g,dmin=max(1,d-g),tf,tx,i,j;
	typedef pair<int,int> pii;
	set<pii> q; 
	fill(f,f+n+1,0); fill(ok,ok+n+1,0); 
	ok[0]=1;
	for(i=1,j=0;i<=n;i++){
		for(;x[j]<=x[i]-dmin;j++)
			if(ok[j]&&x[j]>=x[i]-dmax)
				q.insert(pii(f[j],x[j]));
		while(!q.empty()){
			tf=q.rbegin()->first;
			tx=q.rbegin()->second;
			if(tx>=x[i]-dmax) break;
			q.erase(pii(tf,tx));
		}
		if(q.empty()) continue;
		f[i]=tf+s[i]; ok[i]=1; 
		if(f[i]>=k)return 1;
	}
	return 0;
}
int main(){
	cin>>n>>d>>k;
	x[0]=s[0]=0;
	for(int i=1;i<=n;i++) cin>>x[i]>>s[i];
	int l=0,r=x[n],mid,ans=-1;
	//二分答案范围，目标答案在[l,r]内 
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)) r=ans=mid;
		else l=mid+1;
	}	
	cout<<ans<<endl;
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/

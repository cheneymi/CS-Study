#include<iostream>
#include<set>
#define M 500005
using namespace std;
int n,d,k,f[M],x[M],s[M],ok[M];
struct point{int cost,pos;};
point q[M];
int check(int g){
	int dmax=d+g,dmin=max(1,d-g),tf,tx,i,j;
	int head=0,tail=0; 
	f[0]=0; ok[0]=1;
	for(i=1,j=0;i<=n;i++){
		f[i]=ok[i]=0;
		for(;x[j]<=x[i]-dmin;j++)
			if(ok[j]&&x[j]>=x[i]-dmax){
				while(head<tail&&q[tail-1].cost<f[j]) tail--; 
				q[tail].cost=f[j];
				q[tail++].pos=x[j];
			}
		while(head<tail){
			tf=q[head].cost;
			tx=q[head].pos;
			if(tx>=x[i]-dmax) break;
			head++;
		}
		if(head==tail) continue;
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

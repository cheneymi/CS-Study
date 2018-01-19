#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
struct drink{
	int x,p;
};
drink d[N];
int cmp(const drink& a,const drink& b){
	return a.p<b.p;
}
int main(){
int n,cost=0,capacity=100,amount,i;
	cin>>n;
	for(i=0;i<n;i++) cin>>d[i].x>>d[i].p;
	sort(d,d+n,cmp);
	for(i=0;i<n;i++){
		amount=min(capacity,d[i].x);
		cost+=d[i].p*amount;
		capacity-=amount;
	}
	cout<<cost<<endl;	
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
struct drink{
	int x,p;
};
drink d[3];
int cost,capacity=100,amount,i;
int cmp(const drink& a,const drink& b){
	return a.p<b.p;
}
int main(){
	for(i=0;i<3;i++) cin>>d[i].x>>d[i].p;
	sort(d,d+3,cmp);
	for(i=0;i<3;i++){
		amount=min(capacity,d[i].x);
		cost+=d[i].p*amount;
		capacity-=amount;
	}
	cout<<cost<<endl;	
	return 0;
}

#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
struct order{
	string item;
	double p;
	int id;
};
order d[100005];
int cmp(const order& x,const order& y){
	if(x.item<y.item) return 1;
	if(x.item>y.item) return 0;
	if(x.id<y.id) return 1;
	else return 0;
}
int main() {
    int n,i;
    cin>>n;
    for(i=0;i<n;i++) {
		cin>>d[i].item>>d[i].p;
		d[i].id=i;
	}
    sort(d,d+n,cmp);
    for(i=0;i<n;i++){
    	double tot=d[i].p*0.75;
    	while(i<n and d[i+1].item==d[i].item) 
			tot+=d[++i].p;
    	cout<<d[i].item<<" "<<fixed<<setprecision(2)<<tot<<endl;    	
    }
    return 0;
}

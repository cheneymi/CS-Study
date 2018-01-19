#include<iostream>
using namespace std;
int ans,i,n,c[6],v[6]={1,5,10,20,50,100};
int main(){
	cin>>n;
	for(i=0;i<6;i++) cin>>c[i];
	for(i=5;i>=0;i--) {
		ans+=min(n/v[i],c[i]);
		n%=v[i];
	}
	cout<<ans<<endl;
	return 0;
}


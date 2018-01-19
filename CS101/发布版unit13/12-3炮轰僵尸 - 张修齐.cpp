#include<iostream>
using namespace std;
long long zom[10005],n,m,i,mid,t=0,boms,zero=0;
bool w;
int main(){
	cin>>n;
	for(i=0;i<n;i++)cin>>zom[i];
	w=false;
	while(!w){
		m=1000;
		w=true;
		for(i=0;i<n;i++){
			if(zom[i]>0){
				w=false;
				if(zom[i]<m){
				    m=zom[i];
				    mid=i;
		    	}
			}
		}
		if(w) break;
		boms=zom[mid]/2+zom[mid]%2;
		zom[mid]=0;
		if(mid>0)zom[mid-1]=max(zero,zom[mid-1]-boms);
		if(mid<n-1)zom[mid+1]=max(zero,zom[mid+1]-boms);
		t+=boms;
    }
    cout<<t<<endl;
    return 0;
} 

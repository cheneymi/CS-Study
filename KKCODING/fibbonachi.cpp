#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	cout<<"0"<<" "<<"1"<<" "<<"1"<<" ";
	a[0]=0;
	a[1]=1;
	a[2]=1;
	for(int i=3;i<n;i++){
		a[i]=a[i-1]+a[i-2];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
} 

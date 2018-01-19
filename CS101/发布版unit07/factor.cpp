#include<iostream>
using namespace std;
int main() {
	int n, tot;
	cin>>n;
	for(int i=2; i*i<=n; i++) {
		if (n%i==0) {
			while(n%i==0) {
				n /= i;
				tot++;
				if(tot==1)
					cout<<i;
				else
					cout<<'*'<<i;
			}
		}
	}
	if (n!=1) {
		tot++;
		if(tot==1)
			cout<<n;
		else
			cout<<'*'<<n;
	}
	return 0;
}

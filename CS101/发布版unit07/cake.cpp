#include<iostream>
using namespace std;
int main() {
	int n, k, x, cnt=0, disk=0;
	cin>>n>>k; 
	for (int i=1; i<=n; i++) {
		cin>>x;
		disk+=x;
		if (disk >= k) {
			cnt++;
			disk=0;
		}
	}
	if (disk>0) cnt++;
	cout<<cnt<<endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
string name[100000];
int year[100000];
int main() {
	int n,m,i,j,x; string y;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>name[i]>>year[i];
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		int found=0;
		for(j=0;j<n;j++){
			if(name[j]==y&&year[j]==x){
				found=1;
				break;
			}
		}
		cout<<found<<" ";
	}    
	return 0;
}


#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<string,int> d;
	string x,y;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		d[x]++;//如果x不存在会自动插入x并设置d[x]为0 
	}
	cin>>x>>y;
	//if(d.count(x)) cout<<"Yes"<<endl;
	if(d[x]==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}



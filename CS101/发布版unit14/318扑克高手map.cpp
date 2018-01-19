#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<string,int> d;
	string x,y,z;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		z=x+y;
		if(d[z]>0) {
			cout<<"I am angry"<<endl;
			return 0;
		}
		d[z]++;//如果x不存在会自动插入x并设置d[x]为0 
	}
	cout<<"Nice hand"<<endl;
	return 0;
}



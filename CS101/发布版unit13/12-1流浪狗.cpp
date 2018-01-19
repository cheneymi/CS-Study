#include<iostream>
#include<string>
#include<set>
using namespace std;
struct dog{string name;int year;};
struct cmp{
	bool operator()(const dog&a,const dog&b)const{
		if(a.name<b.name)return 1;
		if(a.name>b.name)return 0;
		if(a.year<b.year)return 1;
		return 0;
	}
};
int main() {
	set<dog,cmp> s;
	int n,m,i;
	dog d;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>d.name>>d.year;
		s.insert(d);
	}
	for(i=0;i<m;i++){
		cin>>d.year>>d.name;
		if(s.count(d)) cout<<"1 ";
		else cout<<"0 ";		
	}    
	return 0;
}


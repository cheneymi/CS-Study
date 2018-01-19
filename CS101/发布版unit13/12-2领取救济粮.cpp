#include<iostream>
#include<string>
#include<set>
using namespace std;
struct ren{int x,id;};
struct cmp{
	bool operator()(const ren&a,const ren&b)const{
		if(a.x<b.x)return 1;
		if(a.x>b.x)return 0;
		if(a.id<b.id)return 1;
		return 0;
	}
};
int main() {
	set<ren,cmp> s;
	set<ren,cmp>::iterator it;
	set<int> cnt;//领过粮食的人放入cnt容器 
	int n,i;
	ren d;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>d.x; d.id=i;
		s.insert(d);
	}
	for(i=0;i<n;i++){
		it=s.begin();
		cnt.insert((*it).id);
		ren e={(*it).x+3,(*it).id};
		s.erase(it); 
		s.insert(e);	
	}    
	cout<<n-cnt.size()<<endl;
	return 0;
}


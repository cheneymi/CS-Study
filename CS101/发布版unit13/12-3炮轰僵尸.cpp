#include<iostream>
#include<cmath>
#include<string>
#include<set>
using namespace std;
struct zombie{int x,id;};
struct cmp{
	bool operator()(const zombie&a,const zombie&b)const{
		if(a.x<b.x)return 1;
		if(a.x>b.x)return 0;
		if(a.id<b.id)return 1;
		return 0;
	}
};
int h[10005],n,i,ans=0;;
set<zombie,cmp> s;
set<zombie,cmp>::iterator it;
int main() {
	cin>>n;
	zombie y,z;
	for(i=0;i<n;i++){
		cin>>h[i];
		if(h[i]>0) s.insert((zombie){h[i],i}); 
	}
	while(!s.empty()){
		it=s.begin(); z=*it;
		s.erase(it); 
		int bombs=ceil(z.x/2.0);
		ans+=bombs;		
		if(z.id-1>=0){
			it=s.find((zombie){h[z.id-1],z.id-1}); 
			if(it!=s.end()){
				h[z.id-1]=max(0,h[z.id-1]-bombs);
				s.erase(it);
				if(h[z.id-1]>0) s.insert((zombie){h[z.id-1],z.id-1});
			}
		}
		if(z.id+1<=n-1){
			it=s.find((zombie){h[z.id+1],z.id+1}); 
			if(it!=s.end()){
				h[z.id+1]=max(0,h[z.id+1]-bombs);
				s.erase(it);
				if(h[z.id+1]>0) s.insert((zombie){h[z.id+1],z.id+1});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


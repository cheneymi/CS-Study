#include<iostream>
#include<set>
using namespace std;

int main(){
	multiset<int> s;
	multiset<int>::iterator it;
	int n,m,x;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>x;
		if(i<=m){
			s.insert(x);//add in x
		}else{
			it=s.begin();//it is smallest
			int a=*it;//a is smallest
			s.erase(it);//remove it
			s.insert(a+x);//add a+x
		}
	}
	int ans=0;
	if(s.size()>0){
		it=s.end();it--;//it is biggest
		ans=*it;
	}
	cout<<ans<<endl;
	return 0;
}

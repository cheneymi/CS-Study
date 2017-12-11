#include<iostream>
#include<set>
using namespace std;

int main(){
	multiset<int> s;
	multiset<int>::iterator it;
	int n,x,tired=0; cin>>n;
	for(int i=0;i<n;i++){
		cin>>x; s.insert(x);
	}
	while(s.size()>1){
		it=s.begin();//find the smallest one
		int a=*it; s.erase(it);//erase out the smallest one
		it=s.begin();//find the smallest one
		int b=*it; s.erase(it);//erase out the smallest one
		s.insert(a+b);//put a+b into s
		tired+=a+b;			
	}
	cout<<tired<<endl;	
	return 0;
}

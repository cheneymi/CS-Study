#include<iostream>
#include<cmath> 
using namespace std;
int main() {
    int b1,b2,b3,b4,b5,b6,ans,n1,n2;
    cin>>b1>>b2>>b3>>b4>>b5>>b6;
    ans=b6+b5+b4+ceil(b3/4.0); 
	//6*6,5*5,4*4��ռһ�䣬3*3ÿ�ĸ�ռһ�� 
    int b[4]={0,5,3,1};
    n2=5*b4+b[b3%4];
    //n2=�����������ܷŶ���2*2 
    if(b2>n2) ans+=ceil((b2-n2)/9.0);
    //���2*2�ڷ� s
    n1=36*(ans-b6)-25*b5-16*b4-9*b3-4*b2;
    if(b1>n1) ans+=ceil((b1-n1)/36.0);
    //���1*1�ڷ� 
    cout<<ans;
    return 0;
}

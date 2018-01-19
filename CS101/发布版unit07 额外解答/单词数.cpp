#include<iostream>
#include<string>
#include MOD 10007
using namespace std;
int main(){
    long long ans = 1;
	string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++)
        ans = ans*(s[i]-'a'+1)%MOD;
    cout<<ans<<endl;
    return 0;
}

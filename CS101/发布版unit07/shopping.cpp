#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    map<string, double> m;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string item;
        double value;
        cin>>item>>value;
        if(m.count(item)==0)
            m[item]=value*0.75;
        else
            m[item]+=value;
    }
    for(map<string, double>::iterator iter=m.begin(); iter!=m.end(); iter++)
        cout<<iter->first<<" "<<fixed<<setprecision(2)<<iter->second<<endl;
    return 0;
}

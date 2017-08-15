#include <iostream>
using namespace std;

int main() {
    long long n,zombies=0;
    cin>>n;
    long long w=n/7;
    int d=n%7;
    zombies+=31*w;
    if(d==1) zombies+=10;
    if(d==2) zombies+=16;
    if(d==3) zombies+=21;
    if(d==4) zombies+=25;
    if(d==5) zombies+=28;
    if(d==6) zombies+=30;
    cout<<zombies<<endl;
    return 0;
}

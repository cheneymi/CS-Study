#include <iostream>
using namespace std;

int main() {
    long long n,zombies=0;//variables initial
    cin>>n;//enter number of days
    long long w=n/7;//how many weeks
    int d=n%7;//how many leftover days
    zombies+=31*w;//zombies per week
    if(d==1) zombies+=10;//1 day+10
    if(d==2) zombies+=16;//2 days+16
    if(d==3) zombies+=21;//3 days+21
    if(d==4) zombies+=25;//4 days+25
    if(d==5) zombies+=28;//5 days+28
    if(d==6) zombies+=30;//6 days+30
    cout<<zombies<<endl;//output most zombies
    return 0;
}
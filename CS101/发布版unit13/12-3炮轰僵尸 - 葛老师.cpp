#include<iostream>
#include <queue>
#define N 10005
using namespace std;
struct zombie{int id,hp;};
bool operator <(zombie a,zombie b){
    return a.hp>b.hp || ((a.hp==b.hp) && (a.id>b.id));
}
int hps[N],n,ans;
int main(){
    cin>>n;
    priority_queue<zombie> q;
    for(int i=0;i<n;i++){
        cin>>hps[i];
        q.push((zombie){i,hps[i]});
    }
    for(;!q.empty();){
        zombie z=q.top(); q.pop();
        if (z.hp!=hps[z.id]) continue;
        int boms=(z.hp+1)>>1;
        hps[z.id]=0;
        if(z.id>0 && (hps[z.id-1]-=boms)>0)
            q.push((zombie){z.id-1,hps[z.id-1]});
        if(z.id<n-1 && (hps[z.id+1]-=boms)>0){
            q.push((zombie){z.id+1,hps[z.id+1]});
        }
        ans+=boms;
    }
    cout<<ans<<endl;
    return 0;
}

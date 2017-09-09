#include <iostream>
using namespace std;

bool ispossibe(int A,int B,int C){
    bool isUsed[10];
    int digit[10];
    if(B>999||C>999){
        return false;
    }
    for(int i=1;i<10;i++)
        isUsed[i]=false;
    digit[1]=A%10;
    digit[2]=(A/10)%10;
    digit[3]=A/100;
    digit[4]=B%10;
    digit[5]=(B/10)%10;
    digit[6]=B/100;
    digit[7]=C%10;
    digit[8]=(C/10)%10;
    digit[9]=C/100;
    for (int j=1;j<10;j++){
        int d=digit[j];
        if(isUsed[d]){
            return false;
        }else{
            isUsed[d]=true;
        }
    }
    return true;
}

int main() {
    int A,B,C;
    int count=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                if(i!=j&&i!=k&&j!=k){
                    A=i*100+j*10+k;
                    B=2*A;
                    C=3*A;
                    if(ispossibe(A,B,C)){
                        cout << A<<" "<<B<<" "<<C<<endl;
                    }
                    count++;
                }
            }
        }
    }
    return 0;
}

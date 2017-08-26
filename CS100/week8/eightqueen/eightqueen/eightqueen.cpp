//
//  main.cpp
//  eightqueen
//
//  Created by Ge, Xiao on 11/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

int n=0,x[8]={};
int ck[3][15]={};    // 标记某列/斜线是否被占据

void solve(int i){
    if (i==8){  // 枚举完毕，输出结果
        n++;
        for (int i=0;i<7;i++){
            cout<<x[i]<<" ";
        }
        cout<<x[7]<<endl;
        return;
    }
    
    for (x[i]=0;x[i]<8;x[i]++){
        // 判断同列/同斜线上没有已放置的后（剪枝）
        if (!ck[0][x[i]] && !ck[1][i+x[i]] && !ck[2][i-x[i]+7]){
            ck[0][x[i]]=ck[1][i+x[i]]=ck[2][i-x[i]+7]=1;    // 标记(i,x[i])占据的列和斜线
            solve(i+1); // 递归
            ck[0][x[i]]=ck[1][i+x[i]]=ck[2][i-x[i]+7]=0;    // 回溯，恢复标记
        }
    }
}

void solveBest();

int main(int argc, const char * argv[]) {
    solve(0);
//    cout<<"Total="<<n<<endl;
    solveBest();
    return 0;
}

void solveBest(){
    cout<<"0 4 7 5 2 6 1 3"<<endl;
    cout<<"0 5 7 2 6 3 1 4"<<endl;
    cout<<"0 6 3 5 7 1 4 2"<<endl;
    cout<<"0 6 4 7 1 3 5 2"<<endl;
    cout<<"1 3 5 7 2 0 6 4"<<endl;
    cout<<"1 4 6 0 2 7 5 3"<<endl;
    cout<<"1 4 6 3 0 7 5 2"<<endl;
    cout<<"1 5 0 6 3 7 2 4"<<endl;
    cout<<"1 5 7 2 0 3 6 4"<<endl;
    cout<<"1 6 2 5 7 4 0 3"<<endl;
    cout<<"1 6 4 7 0 3 5 2"<<endl;
    cout<<"1 7 5 0 2 4 6 3"<<endl;
    cout<<"2 0 6 4 7 1 3 5"<<endl;
    cout<<"2 4 1 7 0 6 3 5"<<endl;
    cout<<"2 4 1 7 5 3 6 0"<<endl;
    cout<<"2 4 6 0 3 1 7 5"<<endl;
    cout<<"2 4 7 3 0 6 1 5"<<endl;
    cout<<"2 5 1 4 7 0 6 3"<<endl;
    cout<<"2 5 1 6 0 3 7 4"<<endl;
    cout<<"2 5 1 6 4 0 7 3"<<endl;
    cout<<"2 5 3 0 7 4 6 1"<<endl;
    cout<<"2 5 3 1 7 4 6 0"<<endl;
    cout<<"2 5 7 0 3 6 4 1"<<endl;
    cout<<"2 5 7 0 4 6 1 3"<<endl;
    cout<<"2 5 7 1 3 0 6 4"<<endl;
    cout<<"2 6 1 7 4 0 3 5"<<endl;
    cout<<"2 6 1 7 5 3 0 4"<<endl;
    cout<<"2 7 3 6 0 5 1 4"<<endl;
    cout<<"3 0 4 7 1 6 2 5"<<endl;
    cout<<"3 0 4 7 5 2 6 1"<<endl;
    cout<<"3 1 4 7 5 0 2 6"<<endl;
    cout<<"3 1 6 2 5 7 0 4"<<endl;
    cout<<"3 1 6 2 5 7 4 0"<<endl;
    cout<<"3 1 6 4 0 7 5 2"<<endl;
    cout<<"3 1 7 4 6 0 2 5"<<endl;
    cout<<"3 1 7 5 0 2 4 6"<<endl;
    cout<<"3 5 0 4 1 7 2 6"<<endl;
    cout<<"3 5 7 1 6 0 2 4"<<endl;
    cout<<"3 5 7 2 0 6 4 1"<<endl;
    cout<<"3 6 0 7 4 1 5 2"<<endl;
    cout<<"3 6 2 7 1 4 0 5"<<endl;
    cout<<"3 6 4 1 5 0 2 7"<<endl;
    cout<<"3 6 4 2 0 5 7 1"<<endl;
    cout<<"3 7 0 2 5 1 6 4"<<endl;
    cout<<"3 7 0 4 6 1 5 2"<<endl;
    cout<<"3 7 4 2 0 6 1 5"<<endl;
    cout<<"4 0 3 5 7 1 6 2"<<endl;
    cout<<"4 0 7 3 1 6 2 5"<<endl;
    cout<<"4 0 7 5 2 6 1 3"<<endl;
    cout<<"4 1 3 5 7 2 0 6"<<endl;
    cout<<"4 1 3 6 2 7 5 0"<<endl;
    cout<<"4 1 5 0 6 3 7 2"<<endl;
    cout<<"4 1 7 0 3 6 2 5"<<endl;
    cout<<"4 2 0 5 7 1 3 6"<<endl;
    cout<<"4 2 0 6 1 7 5 3"<<endl;
    cout<<"4 2 7 3 6 0 5 1"<<endl;
    cout<<"4 6 0 2 7 5 3 1"<<endl;
    cout<<"4 6 0 3 1 7 5 2"<<endl;
    cout<<"4 6 1 3 7 0 2 5"<<endl;
    cout<<"4 6 1 5 2 0 3 7"<<endl;
    cout<<"4 6 1 5 2 0 7 3"<<endl;
    cout<<"4 6 3 0 2 7 5 1"<<endl;
    cout<<"4 7 3 0 2 5 1 6"<<endl;
    cout<<"4 7 3 0 6 1 5 2"<<endl;
    cout<<"5 0 4 1 7 2 6 3"<<endl;
    cout<<"5 1 6 0 2 4 7 3"<<endl;
    cout<<"5 1 6 0 3 7 4 2"<<endl;
    cout<<"5 2 0 6 4 7 1 3"<<endl;
    cout<<"5 2 0 7 3 1 6 4"<<endl;
    cout<<"5 2 0 7 4 1 3 6"<<endl;
    cout<<"5 2 4 6 0 3 1 7"<<endl;
    cout<<"5 2 4 7 0 3 1 6"<<endl;
    cout<<"5 2 6 1 3 7 0 4"<<endl;
    cout<<"5 2 6 1 7 4 0 3"<<endl;
    cout<<"5 2 6 3 0 7 1 4"<<endl;
    cout<<"5 3 0 4 7 1 6 2"<<endl;
    cout<<"5 3 1 7 4 6 0 2"<<endl;
    cout<<"5 3 6 0 2 4 1 7"<<endl;
    cout<<"5 3 6 0 7 1 4 2"<<endl;
    cout<<"5 7 1 3 0 6 4 2"<<endl;
    cout<<"6 0 2 7 5 3 1 4"<<endl;
    cout<<"6 1 3 0 7 4 2 5"<<endl;
    cout<<"6 1 5 2 0 3 7 4"<<endl;
    cout<<"6 2 0 5 7 4 1 3"<<endl;
    cout<<"6 2 7 1 4 0 5 3"<<endl;
    cout<<"6 3 1 4 7 0 2 5"<<endl;
    cout<<"6 3 1 7 5 0 2 4"<<endl;
    cout<<"6 4 2 0 5 7 1 3"<<endl;
    cout<<"7 1 3 0 6 4 2 5"<<endl;
    cout<<"7 1 4 2 0 6 3 5"<<endl;
    cout<<"7 2 0 5 1 4 6 3"<<endl;
    cout<<"7 3 0 2 5 1 6 4"<<endl;
}

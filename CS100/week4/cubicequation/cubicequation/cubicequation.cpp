//
//  main.cpp
//  cubicequation
//
//  Created by Ge, Xiao on 28/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// Sun,Yizhe
double cubiequation(double b,double c,double d,double bottom,double top){
    //因为b，c，d的绝对值不超过100，所以所有实根的绝对值小于101
    double mid,x1;
    while ((top-bottom)>0.001){
        mid=(top+bottom)/2.0;
        x1=mid*mid*mid+b*mid*mid+c*mid+d;
        if (x1>0.0){//mid时大于0
            top=mid;
        }
        else{
            bottom=mid;
        }
    } 
    return int((top+bottom)*500)/1000.0;
}

// Gao,Rui (python)

double getRoot(int b,int c,int d){
    double left=-1000.0,right=1000.0,x=0.0; // 左右边界，结果值
    for (;right-left>1e-3;){    // 二分查找
        x=(left+right)/2;
        double y=x*x*x+b*x*x+c*x+d;
        (y>0?right:left)=x; // 保持left,right的函数值异号
    }
    return x;
}

double getRoot2(int b,int c,int d){
    double x=1.5,x0,f,f1;
    do {
        x0=x;
        f=x*x*x+b*x*x+c*x+d;
        f1= 3*x*x+2*b*x+3*c;// 求导
        x=x-f/f1;
    }while  (fabs(x-x0)>1e-3);
    return x;
}

int main(int argc, const char * argv[]) {
    /* 2 3 4 */
    int b,c,d;
    cin>>b>>c>>d;   // 输入

//    cout<<setprecision(3)<<getRoot(b, c, d)<<endl; // 输出
//    cout<<setprecision(3)<<cubiequation(b, c, d,-1000,1000)<<endl;
    cout<<setprecision(3)<<getRoot2(b, c, d)<<endl; // 输出
    return 0;
}

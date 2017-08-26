//
//  main.cpp
//  syntax
//
//  Created by Ge, Xiao on 02/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

void pointerDemo(){
    int i=1,j=2;
    int* a=0, *b=0;  // 空指针，不是数值0
    a= &i;  // & : 取地址运算符，返回指针类型
    b= &j;
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"*a="<<*a<<" *b="<<*b<<endl; // * : 取值运算符
    
    b=new int(4);   // 动态申请变量，返回对应指针类型
    *a=3;   // 修改指向的值
    cout<<"*a="<<*a<<" *b="<<*b<<endl;
    *a=*b;  // 两个地址具有同样的数值
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"*a="<<*a<<" *b="<<*b<<endl;
    
    a=b;    // 两个指针指向同一内存地址
    *a=5;   // 改变取值，两个指针指向的值都变化
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"*a="<<*a<<" *b="<<*b<<endl;
}

class Point {
public:
    int x,y;
    Point(int x0,int y0){
        x=x0; y=y0;
    }
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

void pointerWithClassDemo(){
    Point p=Point(1,2);
    Point* pt=&p;   // 指针p指向变量pt的地址
    
    cout<<"pt="<<pt<<endl;    // 输出指针变量（值是地址）
    p.print();     // 这三行效果是一样的
    (*pt).print();
    pt->print();
    cout<<endl;

    pt->x=2;     // 改变p指向的值，pt也跟着
    pt->y=3;
    p.print();
    pt->print();
    cout<<endl;
    
    pt=new Point(9,9);   // p指向另一个新的地址
    p.print();     // 这时p指向的值与pt的值无关
    pt->print();
}

int main(int argc, const char * argv[]) {
    pointerDemo();
//    pointerWithClassDemo();
    return 0;
}

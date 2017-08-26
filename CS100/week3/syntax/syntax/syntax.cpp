//
//  main.cpp
//  syntax
//
//  Created by Ge, Xiao on 24/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

class Point {   // 平面上的点
public:
    int x=0,y=0;
    Point(int x0,int y0){ //构造函数（初始化）
        x=x0; y=y0;
    }
    
    void print(){   // 打印点的信息（坐标）
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

class Circle {  // 平面上的圆
public:
    Point ctr = Point(0, 0);  // 圆心
    int r=0;//半径

    Circle(const Point& p,int r0) { //构造函数（初始化）
        ctr=p;
        r=r0;
    }

    double area(){  // 求面积函数
        return 3.1415926*r*r;
    }
    
    void print(){   // 打印圆的信息（坐标）
        cout<<"centre=("<<ctr.x<<","<<ctr.y<<") radius="<<r<<endl;
    }
};

void classDemo(){
    Point pt=Point(1,2);
    pt.print();
    
    pt.x=2; // 修改坐标
    pt.y=3;
    pt.print();
    
    Circle c=Circle(pt, 5);
    c.print();
    cout<<"area="<<c.area()<<endl;
}


int main(int argc, const char * argv[]) {
    classDemo();
    return 0;
}



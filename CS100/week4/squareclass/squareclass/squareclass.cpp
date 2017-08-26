//
//  main.cpp
//  squareclass
//
//  Created by Ge, Xiao on 30/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>

using namespace std;

// Wang,Yuji
class Square {  // 平面上的圆
public:

    int w,h; //宽，高
    
    Square(int w0,int h0) { //构造函数
        w=w0; h=h0;
    }
    int area(){  // 求面积函数
        return w*h;
    }
    int isSquare(){   // 判断是否为正方形
        return w==h;
    }
};

// Liu,Qiyuan
class Rectangle {
private:    // 私有成员变量（无法直接访问）
    double h;
    double w;
public:
    Rectangle(double h, double w) {
        this->h = h;    // 指向本变量的指针
        this->w = w;
    }
    double area(){
        return h * w;
    }
    bool isSquare() {
        return (h == w);
    }
};

int main(int argc, const char * argv[]) {
    Square sq=Square(3,5);
    cout<<"area="<<sq.area()<<endl;
    cout<<"isSquare="<<sq.isSquare()<<endl;

    Rectangle r(500, 1000);
//    r.h=2;
    cout << r.area() << endl;
    cout << r.isSquare() << endl;
    Rectangle abc(12345,12345);
    cout << abc.area() << endl;
    cout << abc.isSquare() << endl;
    return 0;
}

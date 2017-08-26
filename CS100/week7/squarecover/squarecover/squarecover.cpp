//
//  main.cpp
//  squarecover
//
//  Created by Ge, Xiao on 11/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

class Point{    // 点类型
public:
    int x,y;
    int covered=0;  // 标记是否已经被矩形覆盖
};

class Square {   // 矩形类型
public:
    Point left,right,top,bottom;    // 四条边上的点（可能相同）
    Square(Point l,Point r,Point t,Point b){    // 构造函数
        left=l; right=r; top=t; bottom=b;
    }
    
    int area(){ // 返回面积
        return (top.y-bottom.y)*(right.x-left.x);
    }
    
    int isValid(){  // 判断是否构成合法的矩形
        // 上边的y坐标不小于其他三边，etc
        return top.y>=left.y && top.y>=right.y //
            && bottom.y<=left.y && bottom.y<=right.y //
            && left.x<=top.x && left.x<=bottom.x //
            && right.x>=top.x && right.x>=bottom.x;
    }
    
    int covers(Point pt){ // 判断矩形是否覆盖某个点
        return (top.y>=pt.y)&&(bottom.y<=pt.y)&&(left.x<=pt.x)&&(right.x>=pt.x);
    }
};

// 全局变量
int n,k;
int result=INT_MAX; // 最优解
Point points[50];   // 所有的点的坐标

Square* findLastSquare(){   // 当只剩下一个矩形时，直接找到这个矩形（边界裁剪）
    Square* sq=0;
    for (int a=0;a<n;a++){
        if (!points[a].covered){
            if (sq==0){
                sq=new Square(points[a],points[a],points[a],points[a]);
            } else {
                if ( points[a].x<sq->left.x){   // 未覆盖的点中，x坐标最小的为左边，下同
                    sq->left=points[a];
                }
                if ( points[a].x>sq->right.x){
                    sq->right=points[a];
                }
                if ( points[a].y<sq->bottom.y){
                    sq->bottom=points[a];
                }
                if ( points[a].y>sq->top.y){
                    sq->top=points[a];
                }}
        }
    }
    return sq;
}


Point* findLowestPoint(){ // 找到未被覆盖的点钟y坐标最小的点（局部贪心）
    Point* pt=0;
    for (int a=0;a<n;a++){
        if (!points[a].covered && (pt==0 || points[a].y<pt->y)){
            pt=&points[a];
        }
    }
    return pt;
}

// 判断一个矩形是否覆盖到已被覆盖的点（也就是与其他矩形有重叠）
int checkDuplicate(Square sq){
    for (int a=0;a<n;a++){
        if (sq.covers(points[a]) &&  points[a].covered){
            return 1;
        }
    }
    return 0;
}

// 标记/取消标记一个新矩形（辅助函数）
void markSquare(Square sq,int mark){
    for (int a=0;a<n;a++){
        if (sq.covers(points[a])){
            points[a].covered=mark;
        }
    }
}

/* 
 * 回溯法主体函数
 *
 * @param i 当前试图放置第i+1个矩形
 * @param areaNow 之前放置的矩形的总面积
 */
void solve(int i,int areaNow){
    if (areaNow >= result) {
        return; // 如果面积已经比最优解大，就不用算下去了（也是一种剪枝）
    } else if (i==k) {  // 递归边界，k个矩形已经枚举完毕
        // 因为上一层(i=k-1)一定会覆盖所有点，所以这里不用再判断了
        result=areaNow; // 更新最优解
        return;
    } else if (i==k-1) {    // 边界裁剪
        Square* sq=findLastSquare();    // 找到最后一个矩形（一定是合法的，不需要调用isValid
        if (sq != 0 && !checkDuplicate(*sq)){  // 判断不与其他矩形重叠
            solve(i+1, areaNow+sq->area());  // 递归求解下一个（进i==k分支）
        }
        return;
    }
    
    // 找到y坐标最小的一个未覆盖的点，作为下边（局部贪心）
    Point* bottom=findLowestPoint();
    if (bottom==0){
        return;
    }
    
    // 枚举其他三条边
    for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            for (int c=0;c<n;c++){
                
                Square sq=Square(points[a], points[b], points[c], *bottom);
                if (sq.isValid() && !checkDuplicate(sq)){  // 判断该矩形合法，且不与其他矩形重叠
                    markSquare(sq, 1); // 放置当前矩形，更新被其覆盖的点
                    solve(i+1, areaNow+sq.area());  // 递归求解下一个
                    markSquare(sq, 0); // 恢复被改动的全局状态
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    /*4 2
     1 1
     2 2
     3 6
     0 7*/
    cin>>n>>k;
    for (int i=0;i<n;i++){  // 输入
        cin>>points[i].x>>points[i].y;
    }
    solve(0, 0);    // 求解
    
    cout<<result<<endl; // 输出
    return 0;
}

//
//  main.cpp
//  nearestpoint2d
//
//  Created by Ge, Xiao on 24/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include "float.h"

using namespace std;

class Point {  // 点数据结构s
public:
    double x,y;
};

double dis(Point p1, Point p2) { // 距离函数
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double min(double a, double b) {    // 辅助函数
    return a<b ? a:b;
}

/**
 * 归并排序
 *
 * @param data  待排序点数组
 * @param head  起始位置
 * @param tail  结束为止
 * @param byX   以x坐标还是y坐标排序
 */
void sortByMerge(Point data[],int head,int tail,int byX){
    if (head>=tail) { // 递归边界
        return;
    }
    int mid=(head+tail)/2;
    sortByMerge(data,head,mid,byX);   // 排序左子列
    sortByMerge(data,mid+1,tail,byX); // 排序右子列
    
    int left=head, right=mid+1, i=0;    // 左右两个游标
    Point tmp[tail-head+1];   // 存放临时结果
    while (left<=mid || right<=tail) {  // 归并过程
        // 把左右游标中较小的一个放入tmp的当前位置
                if (right>tail || (left<=mid &&
            ((byX && data[left].x<data[right].x)
             ||(!byX && data[left].y<data[right].y)))){
            tmp[i].x=data[left].x;
            tmp[i].y=data[left].y;
            left++;
        } else {
            tmp[i].x=data[right].x;
            tmp[i].y=data[right].y;
            right++;
        }
        i++;
    }
    // 将tmp（排好序的）回填到原数组的head到tail位置
    for (int j=head;j<=tail;j++){
        data[j].x=tmp[j-head].x;
        data[j].y=tmp[j-head].y;
    }
}

// 最优算法，O(n*logn^2)
double solveBest(Point points[],int l,int r) {
    if(l == r) {    // 递归边界
        return DBL_MAX;
    } else if (l == r - 1) {
        return dis(points[l],points[r]);
    }
    
    // 解子问题
    int mid = (l+r) >> 1;
    double d = min(solveBest(points,l,mid),solveBest(points,mid+1,r));
    
    // 筛选出宽度为2d的竖条区域
    Point tmpPoints[r-l+1];
    int t=0;
    for (int i=l;i<=r;i++) {
        if (points[i].x<=points[mid].x+d && points[i].x>=points[mid].x-d) {
            tmpPoints[t].x=points[i].x;
            tmpPoints[t].y=points[i].y;
            t++;
        }
    }
    
    sortByMerge(tmpPoints,0,t-1,0); // y优先排序
    for(int i=0;i<=t-2;i++) {   // 顺序寻找条带区域中距离小于d的点对
        for(int j=i+1;j<=i+5 && j<=t-1 ;j++) {
            d = min(d,dis(tmpPoints[i],tmpPoints[j]));
        }
    }
    return d;
}

// 这是笨办法，O(n^2)
double solve(Point points[],int n){
    double d=DBL_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            d=min(d,dis(points[i],points[j]));
        }
    }
    return d;
}

// 不成功的分治法，实际还是O(n^2)
double solveBetter(Point points[],int l,int r) {
    if(l == r) {    // 递归边界
        return DBL_MAX;
    } else if (l == r - 1) {
        return dis(points[l],points[r]);
    }
    
    // 解子问题
    int mid = (l+r) >> 1;
    double d = min(solveBetter(points,l,mid),solveBetter(points,mid+1,r));
    
    for(int i=l;i<=r-1;i++) {   // 比较左右两边的点距离
        for(int j=i+1;j<=r;j++) {
            d = min(d,dis(points[i],points[j]));
        }
    }
    return d;
}

int main(int argc, const char * argv[]) {
    /* 10
     0 0
     1 100
     2 200
     3 300
     4 400
     5 500
     6 600
     7 700
     8 800
     9 0 */
    int n;
    cin>>n;
    Point points[n];
    for(int i=0;i<n;i++) {
        cin>>points[i].x>>points[i].y;
    }
    sortByMerge(points,0,n-1,1);
//    double ans = solveBest(points,0,n-1);
//    double ans = solve(points,n);
    double ans = solveBetter(points, 0, n-1);
    printf("%.3lf\n",ans);

    return 0;
}

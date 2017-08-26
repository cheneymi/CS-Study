//
//  main.cpp
//  mapcover
//
//  Created by Ge, Xiao on 24/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<int>> map;  // 二维动态数组
int id; // 全局变量，表示当前放入的小组件编号

/*
 * @param n 棋盘边长
 * @param x,y 缺陷的位置
 * @param sx,xy 当前小棋盘左上角在整个大棋盘里的位置（为了填充小组件用）
 */
void cover(int n,int x,int y,int sx,int sy) {
    if (n==1) { // 递归边界，1*1的棋盘，自然不用填充了
        return;
    }
    
    id++;   // 中间一块的id
    int n2=n/2;    // 小棋盘的尺寸
    
    if (x<n2 && y<n2){  // 缺一块在左上子棋盘
        // 放置中间位置的小组件，让三个完整的小棋盘都缺一块
        map[sx+n2][sy+n2-1]=map[sx+n2][sy+n2]=map[sx+n2-1][sy+n2]=id;
        // 递归填充4个小棋盘
        cover(n2, x, y, sx, sy);
        cover(n2, 0, n2-1, sx+n2, sy);
        cover(n2, 0, 0, sx+n2, sy+n2);
        cover(n2, n2-1, 0, sx, sy+n2);
        
    }else if (x>=n2 && y<n2){   // 缺一块在右上子棋盘
        map[sx+n2][sy+n2]=map[sx+n2-1][sy+n2]=map[sx+n2-1][sy+n2-1]=id;
        // 后几个分支只要细心一点就行
        cover(n2, n2-1, n2-1, sx, sy);
        cover(n2, x-n2, y, sx+n2, sy);  // 这个带原始缺陷的小棋盘，注意第2，3个参数的变化
        cover(n2, 0, 0, sx+n2, sy+n2);
        cover(n2, n2-1, 0, sx, sy+n2);
    }else if (x>=n2 && y>=n2){  // 缺一块在右下子棋盘
        map[sx+n2][sy+n2-1]=map[sx+n2-1][sy+n2]=map[sx+n2-1][sy+n2-1]=id;
        cover(n2, n2-1, n2-1, sx, sy);
        cover(n2, 0, n2-1, sx+n2, sy);
        cover(n2, x-n2, y-n2, sx+n2, sy+n2);
        cover(n2, n2-1, 0, sx, sy+n2);
    }else if (x<n2 && y>=n2){  // 缺一块在左下子棋盘
        map[sx+n2][sy+n2-1]=map[sx+n2][sy+n2]=map[sx+n2-1][sy+n2-1]=id;
        cover(n2, n2-1, n2-1, sx, sy);
        cover(n2, 0, n2-1, sx+n2, sy);
        cover(n2, 0, 0, sx+n2, sy+n2);
        cover(n2, x, y-n2, sx, sy+n2);
    }
}

int main(int argc, const char * argv[]) {
    /* 8 2 7 */
    int n,x,y;  // 输入
    scanf("%d%d%d",&n,&x,&y);
    
    // 初始化棋盘
    map=vector<vector<int>>(n);
    for(int i=0; i<n ; i++){
        map[i]=vector<int>(n);
    }
    id=0;

    // 输出
    cover(n, x, y, 0, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(8)<<map[i][j];
        }
        cout<<endl;
    }
    return 0;
}


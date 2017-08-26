//
//  main.cpp
//  eightqueen
//
//  Created by Crystal on 17/6/4.
//  Copyright © 2017年 Cheney. All rights reserved.
//

#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Board {
private:
    bool** spaces;  // 指针方式的二维数组
    int size;   // 棋盘尺寸
    
public:
    Board(int size) {   // 构造函数，创建空棋盘
        this->size = size;
        spaces = new bool*[size];   // 创建二维数组的代码
        for (int i = 0; i < size; ++i) {
            spaces[i] = new bool[size];
        }
    }
    
    Board(Board& other) {   // 构造函数，复制棋盘（同名函数参数类型不同，称为函数重载）
        this->size = other.getSize();
        spaces = new bool*[size];
        for (int i = 0; i < size; ++i) {
            spaces[i] = new bool[size];
            for (int j = 0; j < size; ++j) {
                spaces[i][j] = other.getSpace(j, i);
            }
        }
    }
    
    // 判断新增位置(row,column)是否与之前的冲突（可攻击）
    bool isSafe(int row, int column, vector<int>& state) {
        //check row conflict
        //no need to check for column conflicts
        //because the board is beimg filled column
        //by column
        for(int i = 0; i < column; ++i) {
            if(state[i] == row)
                return false;
        }
        
        //check for diagonal conflicts
        int columnDiff = 0;
        int rowDiff = 0;
        for(int i = 0; i < column; ++i) {
            columnDiff = abs(column - i);
            rowDiff = abs(row - state[i]);
            if(columnDiff == rowDiff)
                return false;
        }
        return true;
        
    }
    
    int getSize() { // getter
        return size;
    }
    
    bool getSpace(int x, int y) { // setter
        return spaces[y][x];
    }
    
    void setSpace(int x, int y, bool value) { // getter
        spaces[y][x] = value;
    }
    
    // 非递归方式的回溯法实现
    bool backtrack(vector<int>& state, int& column, int board_size) {
        int row = 0;
        bool backtrack = column == board_size;  // 是否回溯的标志
        
        // 这是以列为序的回溯法，边界是column==board_size
        while(column < board_size || backtrack) {
            if(backtrack) {
                if (column == 0)    // 回溯到初始，说明已经没有其他解了，返回false
                    return false;
                column--;   // 回溯一列
                row = state[column] + 1;    // 枚举值加一
                if(row == board_size) { // 如果枚举值超过了board_size，说明要继续回溯
                    continue;
                }
                backtrack = false;  // 否则说明枚举到新状态
            }
            
            if (isSafe(row, column, state)) {   // 判断新位置是否有冲突
                state[column] = row;
                column++; // 无冲突则进入下一列枚举
                row = 0; // 下一列从0开始枚举
                backtrack = false;
            } else if(row == (board_size - 1)) {    // 如果有冲突，又枚举到board_size，则回溯
                backtrack = true;
            } else {    // 否则继续枚举下一个值
                row++;
            }
        }
        return true;    // 到这里说明找到一个解
    }
};

// 输出结果
void print_solutions(Board *board, vector<int>& state, int board_size) {
    for(int i=0; i < board_size; ++i) {
        for(int j=0; j < board_size; ++j) {
            cout<<(state[i] == j ? 'Q' : '_') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    
    // 这里注释掉的部分表示从外部传入参数（非console）
    /*
     if (argc < 3)
     {
     cout << "Usage: nqueens [Board Size] [Number of Solutions]" << endl;
     return 1;
     }
     */
    int board_size = 8;//atoi(argv[1]);
    int solution_count = 8;//atoi(argv[2]);
    
    // 初始化
    vector<int> state=vector<int>(board_size);
    Board *my_board = new Board(board_size);
    
    int column = 0; // 逐次回溯法搜索
    while (solution_count-- > 0 && my_board->backtrack(state, column, board_size)){
        print_solutions(my_board, state, board_size);
    }
    return 0;
}

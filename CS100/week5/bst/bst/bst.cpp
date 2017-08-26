//
//  main.cpp
//  bst
//
//  Created by Ge, Xiao on 17/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class BSTree{
private:    // 私有内容，外部不可访问
    BSTree *left=0,*right=0;  // 左右子树
    int value;   // 值

    BSTree* find(int v) {   // 寻找特定值的节点
        if (v==value){  // 当前节点就是
            return this;
        } else if (v<value){    // 递归在左子树查找
            return left==0?0:left->find(v);
        } else {    // 递归在右子树查找
            return right==0?0:right->find(v);
        }
    }

public:
    BSTree(const int& v){    // 初始化
        value=v;
    }

    void insert(int v) {    // 插入
        if (v<value){   // 向左
            if (left==0){ // 如果没有左子树，就创建一个叶节点；否则递归向左子树插入
                left=new BSTree(v);
            } else {    // 否则递归向左子树插入
                left->insert(v);
            }
        } else if (v>value) {   // 向右
            if (right==0) { // 如果没有右子树，就创建一个叶节点；否则递归向右子树插入
                right=new BSTree(v);
            } else {    // 否则递归向右子树插入
                right->insert(v);
            }
        }
        // 等于怎么处理？你自己考虑一下
    }
    
    int exist(int v){   // 返回某个元素是否存在
        return find(v)!=0;
    }
    
    void print(string indent="") {   // 以友好的方式打印（仅供测试用）
        cout<<indent<<value<<"("<<(left!=0?left->value:-1)<<"|"<<(right!=0?right->value:-1)<<")"<<endl;
        if (left!=0){
            left->print(indent+"  ");
        }
        if (right!=0){
            right->print(indent+"  ");
        }
    }
};

void testBST(){ // 这个方法只是给你演示一下BST的操作
    BSTree* tree= new BSTree(20);

    tree->insert(10);
    tree->insert(5);
    tree->insert(1);
    tree->insert(6);
    tree->insert(15);
    tree->insert(16);
    tree->insert(14);
    tree->insert(30);
    tree->insert(35);
    tree->print();
    cout<<endl;
    
    cout<<tree->exist(5)<<endl;
    cout<<tree->exist(7)<<endl;
}

int main(int argc, const char * argv[]) {

    // testBST()
    /*8
     C 13
     C 23
     C 11
     R 31
     R 13
     C 31
     C 99
     R 31*/
    int n;  // 输入指令数量
    cin>>n;
    
    char cmd;
    int value;
    vector<int> result=vector<int>();   // 结果集
    BSTree* tree=new BSTree(0); // 建树
    for (int i=0;i<n;i++){
        cin>>cmd>>value;
        if (cmd=='C'){  // 插入
            tree->insert(value);
        }else if (cmd=='R'){    // 查询
            result.push_back(tree->exist(value));
        }
    }
    
    for (int i=0;i<result.size();i++){  //输出
        cout<<result[i]<<endl;
    }
    return 0;
}

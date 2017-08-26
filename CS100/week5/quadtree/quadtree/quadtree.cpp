//
//  main.cpp
//  quadtree
//
//  Created by Ge, Xiao on 04/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

class QTree{    // 四分树结构（树就是节点，理解一下）
public:
    QTree *children[4]={};  // 四个子节点
    char color=' ';    // 取值为b,w,p
    
    QTree(){}  // 构造函数，这有两个同名函数，参数不同，称为重载（overload）
    QTree(char c){
        color=c;
    }
    
    void addChild(QTree *childs[4]){    // 添加四个子节点（参数是指针数组）
        for (int i=0;i<4;i++){
            children[i]=childs[i];
        }
    }
    
    void print() {   // 输出本节点为根的子树（序列化）
        cout<<color;    // 先输出本节点，然后依次递归输出四个子节点
        for (int i=0;i<4;i++){
            if (children[i]!=0){
                children[i]->print();
            }
        }
    }
};

QTree* buildTree(string s,int &pos){ // 从字符串建立一颗树（反序列化），pos是当前位置
    QTree *root=new QTree(s[pos++]);    // 当前节点
    if (root->color != 'p') { // 叶节点
        return root;
    }
    
    // 递归建四棵子树（好牛掰的一句语句，这里建了一个数组，看出来没有？）
    QTree* childs[4]={buildTree(s, pos),buildTree(s, pos),buildTree(s, pos),buildTree(s, pos)};
    root->addChild(childs); // 添加子树
    return root;
}

void mergeTree(QTree* tr1,QTree* tr2,QTree* tr3){   // 合并两棵树
    if (tr1->color=='b' || tr2->color=='b'){ // 全黑
        tr3->color='b';
    } else if (tr1->color=='w' && tr2->color=='w'){ // 全白
        tr3->color='w';
    } else if (tr1->color=='w'){ // tr1空白，复制tr2子树
        *tr3=*tr2;  // 有没看出隐患？怎么排除？
    } else if (tr2->color=='w'){ // tr2空白，复制tr1子树
        *tr3=*tr1;
    } else {    // 都非纯色，递归处理四个子树
        tr3->color='p';
        for (int i=0;i<4;i++){
            tr3->children[i]=new QTree();
            mergeTree(tr1->children[i],tr2->children[i],tr3->children[i]);
        }
        // 如果合并出纯黑的来，当前节点本身就改成b，去掉所有子节点
        if (tr3->children[0]->color=='b'&&tr3->children[1]->color=='b'
            &&tr3->children[2]->color=='b'&&tr3->children[3]->color=='b'){
            for (int i=0;i<4;i++){
                tr3->children[i]=0;
            }
            tr3->color='b';
        }
        // 为什么没有合并出纯白？
    }
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    cin>>s1>>s2;    // 输入

    int pos=0;
    QTree* tr1= buildTree(s1, pos); // 建树
    pos=0;
    QTree* tr2= buildTree(s2, pos);
    
    QTree* tr3=new QTree(); // 合并
    mergeTree(tr1, tr2, tr3);
    
    tr3->print();   // 输出
    cout<<endl;
}

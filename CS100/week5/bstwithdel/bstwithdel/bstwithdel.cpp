//
//  main.cpp
//  bst
//
//  Created by Ge, Xiao on 17/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>

using namespace std;

class BSTree{
private:    // 私有内容，外部不可访问
    BSTree *left=0,*right=0,*parent=0;  // 左右子树，父节点
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
    
    BSTree* findMax(){ // 寻找当前子树中最大的节点（删除用）
        return right==0?this:right->findMax();
    }
    
    int isLeft(){   // 当前节点是父节点的左子树还是右子树（删除用）
        return parent==0 || value<parent->value;
    }
    
public:
    BSTree(const int& v, BSTree* p){    // 构造函数
        value=v;
        parent=p;
    }
    
    void insert(int v) {    // 插入
        if (v<value){
            if (left==0){ // 如果没有左子树，就创建一个叶节点；否则递归向左子树插入
                left=new BSTree(v,this);
            } else {
                left->insert(v);
            }
        } else if (v>value) {
            if (right==0) { // 如果没有右子树，就创建一个叶节点；否则递归向右子树插入
                right=new BSTree(v,this);
            } else {
                right->insert(v);
            }
        }
    }
    
    int exist(int v){   // 返回某个元素是否存在
        return find(v)!=0;
    }
    
    void remove(int v) {    // 删除（选学）
        BSTree* node=find(v);   // 先找到这个节点
        if (node==0){   // 没找到，直接返回
            return;
        }
        
        if (node->left==0){ // 没有左子树，直接把右子树接到父节点上
            if (node->right!=0){    // 更新子到父的指针
                node->right->parent=node->parent;
            }
            if (node->isLeft()){ // 更新父到子的指针
                node->parent->left=node->right;
            } else{
                node->parent->right=node->right;
            }
        } else {    // 如果有左子树，就取左子树中最大的节点替代被删除的节点
            BSTree* leftMax=node->left->findMax();
            node->value=leftMax->value; // 替换value值
            // 删掉leftMax
            if (leftMax->isLeft()) {    // 父节点改指向leftMax的左子树（leftMax没有右子树）
                leftMax->parent->left=leftMax->left;
            } else {
                leftMax->parent->right=leftMax->left;
            }
            if (leftMax->left!=0) { // 左子树的父节点指向leftMax的父节点
                leftMax->left->parent=leftMax->parent;
            }
        }
    }
    
    void print(string indent="") {   // 以友好的方式打印
        cout<<indent<<(isLeft()?"L:":"R:")<<value<<"("<<(parent!=0?parent->value:-1)<<"|"<<(left!=0?left->value:-1)<<"|"<<(right!=0?right->value:-1)<<")"<<endl;
        if (left!=0){
            left->print(indent+"  ");
        }
        if (right!=0){
            right->print(indent+"  ");
        }
    }
};


int main(int argc, const char * argv[]) {
    BSTree* tree= new BSTree(20,0);
    
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
    
    cout<<endl;
    tree->remove(30);
    tree->remove(10);
    tree->print();
    
    return 0;
}

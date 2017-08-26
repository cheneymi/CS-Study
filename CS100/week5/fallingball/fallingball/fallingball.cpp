//
//  fallingBall.cpp
//  tree
//
//  Created by Ge, Xiao on 01/03/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Node{
public:
    Node *left=0,*right=0;  // 左右子树指针
    int id,status=0;   // 开关id,开关状态
    
    Node(int id0){    // 构造函数，可以理解为初始化函数
        id=id0;
    }
    
    int isLeaf() { // 成员方法，返回当前节点是否是叶子
        return left==0 && right==0;
    }

    void addChild(Node *child,int isleft) { // 添加一个新节点/子树
        (isleft ? left : right) = child;    // 直接设置左右子树字段
    }
};

// 构造以id为根节点，深度为d的完全二叉树
Node* buildTree(int id,int depth){
    if (depth==0) { // 递归边界
        return 0;
    }
    Node *node= new Node(id); // 本节点指针
    
    // 递归构造左右子树，深度减一
    node->addChild(buildTree(id*2, depth-1), 1);
    node->addChild(buildTree(id*2+1, depth-1), 0);
    return node;
}

// 模拟一次下落过程
int fall(Node* node){
    node->status ^= 1;   // 改变当前节点开关
    if (node->isLeaf()){ // 到底了，返回当前id
        return node->id;
    }
    return node->status==1 ? fall(node->left) : fall(node->right); // 选择下一层节点
}

int main(int argc, const char * argv[]) {
    int d, n;
    cin>>d>>n;
    Node *root = buildTree(1,d);
    for (int i=0;i<=n-2;i++) { // 模拟前n-1次
        fall(root);
    }
    cout<<fall(root)<<endl;  // 返回最后一次
    return 0;
}

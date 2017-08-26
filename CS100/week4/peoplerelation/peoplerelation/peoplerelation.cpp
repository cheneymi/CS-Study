//
//  main.cpp
//  peoplerelation
//
//  Created by Ge, Xiao on 30/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include<vector>

using namespace std;

class Person {  // 人物类型
public:
    int id; // 编号
    Person* parent=0;   // 上级，0表示此人为组长
    Person(int id0){    // 初始化函数
        id=id0;
    }
    
    Person* findLeader(){   // 返回此人所在组的组长
        // 如果此人就是组长，返回自己，否则返回上级的组长（本人与上级是同组的）
        Person* leader= parent==0 ? this : parent->findLeader();    // this是一个特殊指针，指向类自身
        if (leader->id!=id){  // 路径压缩优化
            parent=leader;
        }
        return leader;
    }
};

int main(int argc, const char * argv[]) {
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<Person*> people;
    for (int i=0;i<=n;i++){ // 初始化，所有人都自成一组
        people.push_back(new Person(i));
    }
    
    int x,y;
    for (int i=0;i<m;i++){
        cin>>x>>y;
        Person* leaderX=people[x]->findLeader();
        Person* leaderY=people[y]->findLeader();
        // 如果原先不是一组，则合并
        if (leaderX->id != leaderY->id){
            leaderX->parent=leaderY;
        }
    }
    
    vector<int> result;
    for (int i=0;i<k;i++){
        cin>>x>>y;  // 判断x,y是否同组
        Person* leaderX=people[x]->findLeader();
        Person* leaderY=people[y]->findLeader();
        result.push_back(leaderX->id==leaderY->id); // 记录结果
    }
    for (int i=0;i<k;i++){  // 输出
        cout<<result[i]<<endl;
    }
    return 0;
}

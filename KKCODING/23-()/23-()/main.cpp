#include <iostream>
using namespace std;

int main() {
    string exp;
//    char a[100];
    int top=0;
    cin>>exp;
    string ans="YES";
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='('){
            top++;
//            a[top]='(';
        }
        if(exp[i]==')'){
            if(top>0){
                top--;
            }
            else{
                ans="NO";
                break;
            }
        }
    }
    if(top>0){
        ans="NO";
        }
    cout << ans<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    string exp;
    char a[100];
    a[0]='\0';
    int top=0;
    cin>>exp;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='<'){
            top++;
            a[top]='<';
        }
        if(exp[i]=='>'){
            if(top==0){
                cout<<"NO"<<endl;
                return 0;
            }
            else if(a[top]=='<'){
                top--;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(exp[i]=='('){
            if(a[top]=='<')
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else{
                top++;
                a[top]='(';
            }
        }
        if(exp[i]==')'){
            if(top==0){
                cout<<"NO"<<endl;
                return 0;
            }
            else if(a[top]=='('){
                top--;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(exp[i]=='['){
            if(a[top]=='<'||a[top]=='('){
                cout<<"NO"<<endl;
                return 0;
            }
            else{
                top++;
                a[top]='[';
            }
        }
        if(exp[i]==']'){
            if(top==0){
                cout<<"NO"<<endl;
                return 0;
            }
            else if(a[top]=='['){
                top--;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(exp[i]=='{'){
            if(a[top]=='['||a[top]=='<'||a[top]=='('){
                cout<<"NO"<<endl;
                return 0;
            }
            else{
                top++;
                a[top]='{';
            }
        }
        if(exp[i]=='}'){
            if(top==0){
                cout<<"NO"<<endl;
                return 0;
            }
            else if(a[top]=='{'){
                top--;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        }
    if(top>0){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    cout <<endl;
    return 0;
}

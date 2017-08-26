#include <iostream>
using namespace  std;

int main() {
    char s[]="I love Python.";
    
    for(int i=0;i<sizeof(s)-1;i++){
        cout<<int(s[i])<<" ";
    }
    cout<<endl;
    return 0;
}

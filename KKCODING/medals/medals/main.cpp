#include <iostream>
using namespace std;

int main()
{
    int medals[3][4] = {
        {28, 30, 28, 86},
        {19, 19, 12, 50},
        {17, 15, 20, 52}};
    for (int i=0; i < 3; ++i) {  // —≠ª∑√ø“ª––
        for (int j=0; j < 4; ++j) {  // —≠ª∑√ø“ª¡–
            cout << medals[i][j] << " ";  // ¥Ú”° ˝◊È‘™Àÿ
        }
        cout << endl;  // √ø—≠ª∑“ª––∫Û£¨¥Ú”°ªª––
    }
    return 0;
}
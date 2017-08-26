#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

#define HPSIZE 1024

//���� //����洢
struct HP {
    int len;
    int s[HPSIZE + 1];
};

//////////////////////////////////////
//���룬ֻ����������
//////////////////////////////////////
string base_input(string str) {
    char c;

    c = getchar();

    while(c != '\n') {
        str.push_back(c);
        c = getchar();
    }

    return str;
}

/////////////////////////////////////////
//��һ���ַ���ת���ɴ�������a
// a Ŀ�����
// str ԭʼ����
/////////////////////////////////////////
HP change(string str) {
    HP a;
    int i;

    while(str[0] == '0' && str.size() != 1)
        str.erase(0, 1);

    a.len = (int)str.size();

    for(i = 1; i <= a.len; ++i)
        a.s[i] = str[a.len - i] - 48;

    for(i = a.len + 1; i <= HPSIZE; ++i)
        a.s[i] = 0;

    return a;
}

/////////////////////////////////////////
//���
/////////////////////////////////////////
void HPprint(const HP &y) {
    int i;

    for(i = y.len; i >= 1; i--)
        printf("%d", y.s[i]);
}

////////////////////////////////////////
//�Ƚ�������С
//���� a>b -> ����ֵ����0
//   a<b -> ����ֵС��0
//     a=b -> ����0
////////////////////////////////////////
int HPcompare(const HP a, const HP b) {
    int len;

    len = (a.len > b.len) ? a.len : b.len;

    while(len > 0 && a.s[len] == b.s[len])
        len--;

    if(len == 0) return 0;
    else return a.s[len] - b.s[len];
}

/////////////////////////////////////
//�߾��ȼӷ�c=a+b
// a, b ����
// c ��
/////////////////////////////////////
HP HPplus(const HP a, const HP b) {
    HP c;
    int i, len;

    for(i = 1; i <= HPSIZE; i++)
        c.s[i] = 0;

    len = (a.len > b.len) ? a.len : b.len;

    for(i = 1; i <= len; i++) {
        c.s[i] += a.s[i] + b.s[i];

        if(c.s[i] >= 10) {
            c.s[i] -= 10;
            c.s[i + 1]++;
        }
    }

    if(c.s[len + 1] > 0)
        len++;

    c.len = len;
    return c;
}

////////////////////////////////////
//�߾��ȼ���c=a-b
////////////////////////////////////
HP HPsub(const HP a, const HP b) {
    HP c;
    int i, len;

    for(i = 1; i <= HPSIZE; i++)
        c.s[i] = 0;

    len = (a.len > b.len) ? a.len : b.len;

    for(i = 1; i <= len; i++) {
        c.s[i] += a.s[i] - b.s[i];

        if(c.s[i] < 0) { //��λ
            c.s[i] += 10;
            c.s[i + 1]--; //��λ��������ĺ�
        }
    }

    while(len > 1 && c.s[len] == 0)
        len--;

    c.len = len;
    return c;
}
int main(void) {
    string str_a, str_b;
    HP a, b;
    cin >> str_a >> str_b;
    a = change(str_a); //��һ���ַ���ת���ɴ�������a
    b = change(str_b);
    HPprint(HPsub(a, b));  //���м�������
    return 0;
}

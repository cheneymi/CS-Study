#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_extra_size 10
typedef struct {
    int *base;
    int *top;
    int stacksize;
} stack, *pstack;
void initstack(stack &s) {
    s.base = (int *)malloc(stack_size * sizeof(int));
    s.top = s.base;
    s.stacksize = stack_size;
}
void push(stack &s, int e) {
    if(s.top - s.base >= s.stacksize) {
        s.base = (int *)realloc(s.base, (stack_size + stack_extra_size) * sizeof(int));

        if(!s.base)exit(-1);

        s.top = s.base + s.stacksize;
        s.stacksize += stack_extra_size;
    }

    *s.top = e;
    s.top++;
}
int pop(stack &s, int &e) {
    if(s.top == s.base)  return 0;
    else {
        e = *(--s.top);
        return 1;
    }
}
int stackempty(stack s) {
    if(s.top == s.base)return 1;
    else return 0;
}
void datechange(int a, int N) {
    stack s;
    int e;
    initstack(s);

    while(a) {
        push(s, a % N);
        a /= N;
    }

    while(!stackempty(s)) {
        pop(s, e);
        printf("%d", e);
    }

    printf("\n");
}
void sixteenchange(int n) {
    int e;
    stack s;
    initstack(s);

    while(n) {
        push(s, n % 16);
        n /= 16;
    }

    while(!stackempty(s)) {
        pop(s, e);

        switch(e) {
        case 10:
            printf("A");
            break;

        case 11:
            printf("B");
            break;

        case 12:
            printf("C");
            break;

        case 13:
            printf("D");
            break;

        case 14:
            printf("E");
            break;

        case 15:
            printf("F");
            break;

        default :
            printf("%d", e);
            break;
        }
    }

    printf("\n");
}
int main() {
    int n, N;
    char k = ' ';
    printf("����������Ҫ��10����ת����Ľ���������һ���м��֣����ڵ���10��ֻ��16���ƣ�");
    scanf("%d", &N);
    printf("������һЩ10��������Ȼ��ת��Ϊ%d����\n", N);

    while(k != '#') {
        printf("������һ������");
        scanf("%d", &n);
        printf("ת��Ϊ%d���ƺ�Ϊ��", N);

        if(N == 16) sixteenchange(n);
        else datechange(n, N);

        printf("���������? \n�����밴�������������밴#����");
        getchar();
        scanf("%c", &k);
    }
}


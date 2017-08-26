#include <stdio.h>
#define size 100                    /* 输入人数的上限 */
int main() {
    int person[size];
    int i, j;                        /* 循环修正变量 */
    int arrayLen;                    /* 数组长度 */
    int start, overNum;              /* 开始位置各跨过位置 */
    int deleNum;                     /* 出列人所在数组中的下标 */
    int name, total;                 /* 输入时,人的信息以及人的总数 */
    printf("请输入圆桌上人的总数: ");
    scanf("%d", &arrayLen);
    printf("\n");

    if((arrayLen > size) || (arrayLen < 0)) {
        printf("超出范围,请重新输入: ");
        scanf("%d", &arrayLen);
        printf("\n");
    };

    printf("请输入各个人的信息(整数): \n");

    for(i = 0; i < arrayLen; i++) {
        scanf("%d", &name);
        person[i] = name;
    }

    printf("你输入的数据的顺序为: \n");

    for(i = 0; i < arrayLen - 1; i++)
        printf(" %d ==>", person[i]);

    printf("%d \n", person[arrayLen - 1]);
    printf("你打算从第几个人开始? 请输入开始号: ");
    scanf("%d", &start);
    printf("\n");
    start = start - 1;
    printf("请输入相邻两出列人之间的间隔: ");
    scanf("%d", &overNum);
    printf("\n");

    total = arrayLen;
    printf("程序运行后,出列人的顺序为:\n\n");

    for(i = 0; i < total; i++) {                    /* 要打印total个人的情况,故做total次 */
        if(arrayLen == 1)
            printf("%d", person[0]);                      /* 如果是数组只剩一个元素,直接出列 */
        else {
            deleNum = (start + overNum - 1) % arrayLen;   /* 此取模保证循环 */
            printf("%d ==> ", person[deleNum]);

            for(j = deleNum; j < arrayLen; j++)           /* 将出列元素后面的各元素前移 */
                person[j] = person[j + 1];

            start = deleNum;
            arrayLen = arrayLen - 1;                      /* 移动完毕后,数组长度减1 */
        }
    }

    printf("\n\n");
}


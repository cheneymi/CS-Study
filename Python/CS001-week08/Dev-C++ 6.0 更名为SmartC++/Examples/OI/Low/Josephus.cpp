#include <stdio.h>
#define size 100                    /* �������������� */
int main() {
    int person[size];
    int i, j;                        /* ѭ���������� */
    int arrayLen;                    /* ���鳤�� */
    int start, overNum;              /* ��ʼλ�ø����λ�� */
    int deleNum;                     /* ���������������е��±� */
    int name, total;                 /* ����ʱ,�˵���Ϣ�Լ��˵����� */
    printf("������Բ�����˵�����: ");
    scanf("%d", &arrayLen);
    printf("\n");

    if((arrayLen > size) || (arrayLen < 0)) {
        printf("������Χ,����������: ");
        scanf("%d", &arrayLen);
        printf("\n");
    };

    printf("����������˵���Ϣ(����): \n");

    for(i = 0; i < arrayLen; i++) {
        scanf("%d", &name);
        person[i] = name;
    }

    printf("����������ݵ�˳��Ϊ: \n");

    for(i = 0; i < arrayLen - 1; i++)
        printf(" %d ==>", person[i]);

    printf("%d \n", person[arrayLen - 1]);
    printf("�����ӵڼ����˿�ʼ? �����뿪ʼ��: ");
    scanf("%d", &start);
    printf("\n");
    start = start - 1;
    printf("������������������֮��ļ��: ");
    scanf("%d", &overNum);
    printf("\n");

    total = arrayLen;
    printf("�������к�,�����˵�˳��Ϊ:\n\n");

    for(i = 0; i < total; i++) {                    /* Ҫ��ӡtotal���˵����,����total�� */
        if(arrayLen == 1)
            printf("%d", person[0]);                      /* ���������ֻʣһ��Ԫ��,ֱ�ӳ��� */
        else {
            deleNum = (start + overNum - 1) % arrayLen;   /* ��ȡģ��֤ѭ�� */
            printf("%d ==> ", person[deleNum]);

            for(j = deleNum; j < arrayLen; j++)           /* ������Ԫ�غ���ĸ�Ԫ��ǰ�� */
                person[j] = person[j + 1];

            start = deleNum;
            arrayLen = arrayLen - 1;                      /* �ƶ���Ϻ�,���鳤�ȼ�1 */
        }
    }

    printf("\n\n");
}


#include <stdio.h>
#include <stdlib.h>

/* �� int ���Ͷ������ datatype */
typedef int datatype;

/* ������������ */
datatype** Create(int m, int n);
void Reset(datatype**, int, int);
void Input(datatype**, int, int);
void Output(datatype**, int, int);
void MatrixMutiply(datatype**, datatype**, datatype**);
void MatrixFree(datatype** , int);

/* ����������������д�С */
int row_a, col_a;
int row_b, col_b;
int row_c, col_c;

/* �����ļ�ָ�� */
FILE *fp;

int main(void) {
    int i;
    datatype **a, **b, **c; 

	fp = stdin;

    /* �������������a */
    fscanf(fp, "%d%d", &row_a, &col_a);
    a = Create(row_a, col_a);
    Input(a, row_a, col_a);

    /* �������������b */
    fscanf(fp, "%d%d", &row_b, &col_b);
    b = Create(row_b, col_b);
    Input(b, row_b, col_b);

	fp = stdout;

    /* �ж����������ܷ���� */
    if(col_a == row_b) {
        row_c = row_a;
        col_c = col_b;
    } else {
        fprintf(fp, "Matrix Can't Mutiply !\n");
        exit(0);
    }

    /* ��������ʼ���������c */
    c = Create(row_c, col_c);
    Reset(c, row_c, col_c);

    /* ���о���˷����� */
    MatrixMutiply(a, b, c);

    /* ����������C */
    Output(c, row_c, col_c);

    /* �ر�����ļ� */
    fclose(fp);

    /* �ͷž����ڴ� */
    MatrixFree(a, row_a);
    MatrixFree(b, row_b);
    MatrixFree(c, row_c);

    //system("pause");
    return 0;
}

/* Ϊ����̬�����ڴ�ĺ��� */
datatype** Create(int m, int n) {
    int i;
    datatype **Matrix;
    Matrix = (datatype **) malloc(sizeof(datatype *) * m);

    for(i = 0; i < m; i++) {
        Matrix[i] = (datatype *) malloc(sizeof(datatype) * n);
    }

    return Matrix;
}

/* ��ʼ�������� */
void Reset(datatype** Matrix, int m, int n) {
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            Matrix[i][j] = 0;
        }
    }
}

/* �������ݺ��� */
void Input(datatype** Matrix, int m, int n) {
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            fscanf(fp, "%d", &Matrix[i][j]);
        }
    }
}

/* ������ݺ��� */
void Output(datatype** Matrix, int m, int n) {
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            fprintf(fp, "%d ", Matrix[i][j]);
        }

        fprintf(fp, "\n");
    }
}

/* ����˷����㺯�� */
void MatrixMutiply(datatype** a, datatype** b, datatype** c) {
    int i, j, k;

    for(i = 0; i < row_c; i++) {
        for(j = 0; j < col_c; j++) {
            for(k = 0; k < col_a; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/* �ͷž����ڴ溯�� */
void MatrixFree(datatype** Matrix, int m) {
    int i;

    for(i = 0; i < m; i++) {
        free(Matrix[i]);
    }

    free(Matrix);
}

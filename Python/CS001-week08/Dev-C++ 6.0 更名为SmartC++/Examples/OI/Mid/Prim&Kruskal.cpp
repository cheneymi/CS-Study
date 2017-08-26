/*
 * ����ķ�㷨�Ϳ�³˹�����㷨����С������
 * �����ڽӾ���洢
 *
 */
#include<stdio.h>

#define MAX_VERTEX_NUM 200
//ͼ�Ķ���
typedef struct {
    int vertexNum;
    int edgeNum;
    char vertex[MAX_VERTEX_NUM];
    int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
} Graph, *PGraph;

//��������Ԫ��
typedef struct {
    int from;
    int to;
    int weight;
    int flag;
} ArrayNode;

//����������
void createdGraph(PGraph g) {
    int i, j;
    g->vertexNum = 6;
    g->edgeNum = 10;

    for(i = 0; i < g->vertexNum; i++)
        g->vertex[i] = 'A' + i;

    for(i = 0; i < g->vertexNum; i++)
        for(j = 0; j < g->vertexNum; j++)
            g->arc[i][j] = 0;

    g->arc[0][1] = 6;
    g->arc[0][2] = 1;
    g->arc[0][3] = 5;
    g->arc[1][0] = 6;
    g->arc[1][2] = 5;
    g->arc[1][4] = 3;
    g->arc[2][0] = 1;
    g->arc[2][1] = 5;
    g->arc[2][3] = 5;
    g->arc[2][4] = 6;
    g->arc[2][5] = 4;
    g->arc[3][0] = 5;
    g->arc[3][2] = 5;
    g->arc[3][5] = 2;
    g->arc[4][1] = 3;
    g->arc[4][2] = 6;
    g->arc[4][5] = 6;
    g->arc[5][2] = 4;
    g->arc[5][3] = 2;
    g->arc[5][4] = 6;
}

//��ʼ����С������
void initTree(PGraph tree) {
    int i, j;
    tree->vertexNum = 6;
    tree->edgeNum = 5;

    for(i = 0; i < tree->vertexNum; i++)
        tree->vertex[i] = '0';

    for(i = 0; i < tree->vertexNum; i++)
        for(j = 0; j < tree->vertexNum; j++)
            tree->arc[i][j] = 0;
}

//����ķ�㷨����С������
void prim(PGraph g, PGraph tree) {
    int i, j, k;
    int index;  //ָ��Ȩֵ��С�ı�
    ArrayNode  edgeArray[MAX_VERTEX_NUM * 2]; //��������
    int length = 0; //���鳤��
    int n = 1; //ͳ�������Ѽ�����ٸ�����

    //��ʼ״̬�ѵ�һ�������������
    tree->vertex[0] = 'A';
    printf("%-3c", tree->vertex[0]);
    i = 0;

    while(1) {
        //Ѱ���붥��i����������ߵ���һ�����㲻�����еı�,����edgeArray������
        for(j = 0; j < g->vertexNum; j++) {
            if(g->arc[i][j] > 0) {
                //�ж������ߵ���һ�������ڲ�������
                for(k = 0; k < tree->vertexNum; k++) {
                    if(tree->vertex[k] == g->vertex[j])
                        break;
                }

                if(k == tree->vertexNum) {
                    edgeArray[length].from = i;
                    edgeArray[length].to = j;
                    edgeArray[length].weight = g->arc[i][j];
                    edgeArray[length].flag = 0;
                    length++;
                }
            }
        }

        //��������ѡ��Ȩֵ��С�ı�
        index = -1;

        for(j = 0; j < length; j++) {
            if(index == -1 && edgeArray[j].flag == 0)
                index = j;

            if(edgeArray[j].flag == 0 && edgeArray[j].weight < edgeArray[index].weight)
                index = j;
        }

        //�����м���һ�����㣬�Ұ�����Ȩֵ��С�ı߼�������
        tree->vertex[edgeArray[index].to] = 'A' + edgeArray[index].to;
        edgeArray[index].flag = 1;
        tree->arc[edgeArray[index].from][edgeArray[index].to] = edgeArray[index].weight;
        tree->arc[edgeArray[index].to][edgeArray[index].from] = edgeArray[index].weight;

        //����������������ʱ��������������ڵı߲��ɼ�������
        for(k = 0; k < length; k++) {
            if(edgeArray[k].to == edgeArray[index].to)
                edgeArray[k].flag = 1;
        }

        i = edgeArray[index].to;
        printf("%-3c", tree->vertex[i]);
        n++;

        //����g->vertexNum������ʱ����С�������������
        if(n == g->vertexNum)
            break;
    }
}

//�ж����������Ƿ���ͨ���������������
int connected(PGraph tree, int from, int to) {
    int i, j, k;
    int vertex[MAX_VERTEX_NUM];//���ɶ���
    int front, rear;

    if(from == to)
        return 1;

    front = rear = 0;
    //�ѵ�һ�������������
    vertex[rear++] = from;

    //����tree
    while(front <= rear) {
        i = vertex[front];

        for(j = 0; j < tree->vertexNum; j++)
            if(tree->arc[i][j] > 0) {
                if(j == to)
                    return 1;

                //�жϴ˶����Ƿ��ڶ�����
                for(k = 0; k < rear; k++)
                    if(vertex[k] == j)
                        break;

                if(k == rear)
                    vertex[rear++] = j;
            }

        front++;
    }

    return 0;
}

//��³˹�����㷨����С������
void kruskal(PGraph g, PGraph tree) {
    ArrayNode  edgeArray[MAX_VERTEX_NUM]; //��������
    int length = 0;
    int i, j, k, index, n;

    //�����ȼ�������
    for(i = 0; i < tree->vertexNum; i++)
        tree->vertex[i] = i + 'A';

    //1.�����еı�����(��С����)�Ĳ���edgeArray������
    for(i = 0; i < g->vertexNum; i++)
        for(j = 0; j < g->vertexNum; j++) {
            if(i < j && g->arc[i][j] > 0) {
                //Ѱ�Ҳ����λ��index
                for(k = 0; k < length; k++) {
                    if(edgeArray[k].weight > g->arc[i][j])
                        break;
                }

                index = k;

                //��λ
                for(k = length; k > index; k--)
                    edgeArray[k] = edgeArray[k - 1];

                //����
                length++;
                edgeArray[index].flag = 0;
                edgeArray[index].from = i;
                edgeArray[index].to = j;
                edgeArray[index].weight = g->arc[i][j];
            }
        }

    //2.��С����ȡ��n-1���߹�����С������
    n = 0;

    while(n < g->vertexNum - 1) {
        //��С����ȡһ������Ҫ��ı�
        for(k = 0; k < length; k++)
            if(edgeArray[k].flag == 0 && connected(tree, edgeArray[k].from, edgeArray[k].to) == 0) {
                break;
            }

        //�������߼�������
        tree->arc[edgeArray[k].from][edgeArray[k].to] = edgeArray[k].weight;
        tree->arc[edgeArray[k].to][edgeArray[k].from] = edgeArray[k].weight;
        edgeArray[k].flag = 1;
        printf("%-3d", edgeArray[k].weight);
        n++;
    }
}

int main() {
    Graph graph;
    Graph tree;
    createdGraph(&graph);
    initTree(&tree);
    printf("����ķ�㷨���ж�������˳��:\n");
    prim(&graph, &tree);
    printf("\n");
    initTree(&tree);
    printf("��³˹�����㷨���б߼����˳��:\n");
    kruskal(&graph, &tree);
    printf("\n");
}

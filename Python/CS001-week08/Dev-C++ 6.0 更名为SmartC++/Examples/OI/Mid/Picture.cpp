#include <stdio.h>
int m, n, i, j, k;
int row, col, max = -1;
int space[51][51];
char draw[1000][1000];
int lie, hang, lie1, hang1;
void drawing(int row, int col);
int main() {
	printf("小渊是个聪明的孩子，他经常会给周围的小朋友们讲些自己认为有趣的内容。最近，他准备给小朋友讲解立体图，请你帮他画出立体图。\n小渊有一块面积为m*n的矩形区域，上面有m*n个边长为1的格子，每个格子上堆了一些同样大小的积木（积木的长宽高都是1），小渊想请你打印出这些格子的立体图。我们定义每个积木为如下格式，并且不会做任何翻转旋转，只会严格以这样的一种形式摆放：\n  +---+\n /   /|\n+---+ |\n|   | +\n|   |/\n+---+\n每个顶点用1个加号'＋'表示，长用3个'－'表示，宽用1个'/'表示，高用两个'|'表示。字符'＋'，'－'，'/'，'|'的ASCII码分别为43，45，47，124。字符'.'（ASCII码46）需要作为背景输出，即立体图里的空白部分需要用'.'来代替。立体图的画法如下面的规则：\n若两块积木左右相邻，图示为：\n..+---+---+\n./   /   /|\n+---+---+ |\n|   |   | +\n|   |   |/.\n+---+---+..\n若两块积木上下相邻，图示为：\n..+---+\n./   /|\n+---+ |\n|   | +\n|   |/|\n+---+ |\n|   | +\n|   |/.\n+---+..\n若两块积木前后相邻，图示为：\n....+---+\n.../   /|\n..+---+ |\n./   /| +\n+---+ |/.\n|   | +..\n|   |/...\n+---+....\n立体图中，定义位于第(m,1)的格子（即第m行第1列的格子）上面自底向上的第一块积木（即最下面的一块积木）的左下角顶点为整张图最左下角的点。\n输入格式\n输入第一行有用空格隔开的2个整数m和n，表示有m*n个格子（1<=m,n<=50）。\n接下来的m行，是一个m*n的矩阵，每行有n个用空格隔开的整数，其中第i行第j列上的整数表示第i行第j列的格子上摞有多少个积木（1<=每个格子上的积木数<=100）。\n输出格式\n输出包含题目要求的立体图，是一个K行L列的字符矩阵，其中K和L表示最少需要K行L列才能按规定输出立体图。\n\n");
	
    scanf("%d%d", &m, &n);

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++) {
            scanf("%d", &space[i][j]);

            if(max < (1 + (m - i + 1) * 2 + 3 * space[i][j]))
                max = (1 + (m - i + 1) * 2 + 3 * space[i][j]);

        }

    row = 4 * n + 2 * m + 1;
    col = max;
    lie = 1 + (m - 1) * 2;
    hang = col - (m - 1) * 2;

    for(i = 1; i <= col; i++)
        for(j = 1; j <= row; j++)
            draw[i][j] = '.';

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            for(k = 1; k <= space[i][j]; k++) {
                drawing(hang, lie);
                hang -= 3;
            }

            lie = 1 + (m - i) * 2;
            hang = col - (m - i) * 2;
            lie += j * 4;
        }

        lie = 1 + (m - 1) * 2;
        hang = col - (m - 1) * 2;
        hang += i * 2;
        lie -= i * 2;
    }


    for(i = 1; i <= col; i++) {
        for(j = 1; j <= row; j++)
            printf("%c", draw[i][j]);

        printf("\n");
    }

    return 0;
}
void drawing(int row, int col) {
    int i, j;
    draw[row][col] = '+';
    draw[row - 1][col] = '|';
    draw[row - 2][col] = '|';
    draw[row - 3][col] = '+';
    draw[row][col + 1] = '-';
    draw[row - 1][col + 1] = ' ';
    draw[row - 2][col + 1] = ' ';
    draw[row - 3][col + 1] = '-';
    draw[row - 4][col + 1] = '/';
    draw[row][col + 2] = '-';
    draw[row - 1][col + 2] = ' ';
    draw[row - 2][col + 2] = ' ';
    draw[row - 3][col + 2] = '-';
    draw[row - 4][col + 2] = ' ';
    draw[row - 5][col + 2] = '+';
    draw[row][col + 3] = '-';
    draw[row - 1][col + 3] = ' ';
    draw[row - 2][col + 3] = ' ';
    draw[row - 3][col + 3] = '-';
    draw[row - 4][col + 3] = ' ';
    draw[row - 5][col + 3] = '-';
    draw[row][col + 4] = '+';
    draw[row - 1][col + 4] = '|';
    draw[row - 2][col + 4] = '|';
    draw[row - 3][col + 4] = '+';
    draw[row - 4][col + 4] = ' ';
    draw[row - 5][col + 4] = '-';

    draw[row - 1][col + 5] = '/';
    draw[row - 2][col + 5] = ' ';
    draw[row - 3][col + 5] = ' ';
    draw[row - 4][col + 5] = '/';
    draw[row - 5][col + 5] = '-';
    draw[row - 2][col + 6] = '+';
    draw[row - 3][col + 6] = '|';
    draw[row - 4][col + 6] = '|';
    draw[row - 5][col + 6] = '+';
}

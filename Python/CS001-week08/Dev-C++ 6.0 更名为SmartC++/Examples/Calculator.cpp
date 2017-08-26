#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
const char NUM[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
const char OPERATION[] = {'+', '-', '*', '/'};
const double PI = 3.14159265358979;
const double EE = 2.71828182818281;
class Fun { //����ϵͳ��ѧ��������
public:
    Fun(string o, int t, double l = 0.0, double r = 0.0): op(o), type(t), lvalue(l), rvalue(r) {}
    static string FUN[];
    double calc();
private:
    int type; //666 0 1 sin90 2 3! 3 3C2
    string op; //��������
    double lvalue; //������ߵ�ֵ
    double rvalue; //�����ұߵ�ֵ
    static int FunNum;
};
int Fun::FunNum = 10;
string Fun::FUN[] = {"!", "sin", "cos", "tan", "log", "ln", "C", "A", "^", "-"};
/*
����˵��:
1:log����10Ϊ�׵Ĺ��̶���
2:ln ����eΪ�׵���Ȼ����
3:C ��������� ������� ����� 3ȡ2����� ������ʽ 3C2
4:A ���������� ������� ����� 3ȡ2������ ������ʽ 3A2
5:! ����׳�
6:^ x��y�η� ���� x^y
*/
int factorial(int n) { //�׳˺���
    int i, s = 1;

    for(i = 1; i <= n; i++)
        s *= i;

    return s;
}
int C(int a, int b) {
    return factorial(a) / (factorial(b) * factorial(a - b));
}
int A(int a, int b) {
    return factorial(a) / factorial(b);
}
double Fun::calc() { //����ϵͳ������ֵ
    if(type == 0)
        return lvalue;
    else {
        if(op == "!")
            return factorial(lvalue);

        if(op == "sin")
            return sin(rvalue / 180 * PI);

        if(op == "cos")
            return cos(rvalue / 180 * PI);

        if(op == "tan")
            return tan(rvalue / 180 * PI);

        if(op == "log")
            return log10(rvalue);

        if(op == "ln")
            return log10(rvalue) / log10(EE);

        if(op == "C")
            return C(lvalue, rvalue);

        if(op == "A")
            return A(lvalue, rvalue);

        if(op == "^")
            return pow(lvalue, rvalue);

        if(op == "-")
            return -rvalue;
        else {
            string err = "��ʱû�к���" + op;
            MessageBox(NULL, err.c_str(), "����", MB_OK);
            return 0;
        }
    }
}
struct Unit { //˫�����������㵥Ԫ
    Unit(int p, char o, string c, double v, int t, Unit * pr = NULL, Unit * n = NULL)
        : PRI(p), Operation(o), Code(c), value(v), Type(t), Pre(pr), Next(n) {}
    int PRI; //���ȼ�
    char Operation; //������
    string Code; //ԭʼ����
    double value; //����
    int Type; //���� ������0 ����1 ����2
    Unit * Pre; //����˫������
    Unit * Next;
};
class Node { //���ʽ��״�ṹ�Ľڵ�
public:
    Node(char o, int p, int e = 1, double v = 0, Node * ph = NULL, Node * pl = NULL, Node * pr = NULL)
        : Operation(o), PRI(p), Expression(e), value(v), Head(ph), Left(pl), Right(pr) {}
    Node * Head; //�ڵ�ĸ�,����֦,����֦
    Node * Left;
    Node * Right;
    double GetValue();
    char GetOperation() const {
        return Operation;
    }
    int GetPri() const {
        return PRI;
    }
    int IsExp() const {
        return Expression;
    }
private:
    char Operation; //������
    int PRI; //���ȼ�
    int Expression; //��¼�ýڵ��Ƿ��Ǳ��ʽ0 1
    double value; //�ýڵ��ֵ
};
double Node::GetValue() { //����ýڵ��ֵ
    if(IsExp()) { //�ýڵ��ֵ��δ�����
        double lvalue, rvalue;
        lvalue = Left->GetValue();
        rvalue = Right->GetValue();
        Expression = 0;
        char op = GetOperation();

        switch(op) {
        case '+':
            return lvalue + rvalue;

        case '-':
            return lvalue - rvalue;

        case '*':
            return lvalue * rvalue;

        case '/':
            return lvalue / rvalue;

        default:
            return 0;
        }
    } else
        return value;
}
bool Isnum(char c) {
    for(int i = 0; i < sizeof(NUM); i++) {
        if(c == NUM[i])
            return true;
    }

    return false;
}
bool Isoperation(char c) {
    for(int i = 0; i < sizeof(OPERATION); i++) {
        if(c == OPERATION[i])
            return true;
    }

    return false;
}
Unit * Analyse(string exp) { //�������ʽ����������
    int pri = 0; //��ǰ���ȼ�
    int stat = 1; //��ǰ�Ķ���״̬ ���� 0 ����� 1 ���� 2
    Unit * head = NULL, * p = NULL;
    int i = 0, explen;
    explen = exp.size();

    for(i = 0; i < explen; i++) {
        char c = exp.at(i);

        if(c == '(') {
            pri += 3;
            stat = 0;
        } else if(c == ')') {
            pri -= 3;
            stat = 0;
        } else if(Isoperation(c) && stat != 1) { //��������ĵ������Ŵ���
            stat = 1;
            Unit * temp = p;
            int add_pri; //�������ӵ����ȼ�

            if(c == '+' || c == '-')
                add_pri = 1;
            else
                add_pri = 2;

            p->Next = new Unit(pri + add_pri, c, " ", 0, 0);
            p = p->Next;
            p->Pre = temp;
        } else { //�����ĵ�����������
            stat = 2;
            string function = "";

            while(i < explen && (c = exp.at(i), ! Isoperation(c)) && c != ')') {
                function += c;
                i++;
            }

            i--;

            if(head == NULL) {
                p = new Unit(pri, ' ', function, 0, 2);
                head = p;
            } else {
                Unit * temp = p;
                p->Next = new Unit(pri, ' ', function, 0, 2);
                p = p->Next;
                p->Pre = temp;
            }
        }
    }

    return head;
}
Unit * Calc(Unit * head) { //����˫�����������Ԫ��ֵ
    Unit * p = head;

    while(p != NULL) {
        if(p->Type != 0) { //�ǲ�����
            string temp = p->Code;
            string op;
            double lvalue = 0, rvalue = 0;
            int l_point = 0, r_point = 0;
            int i = 0, type = 0;
            char ch;

            while(i < temp.size() && (ch = temp.at(i), Isnum(ch))) {
                if(ch == '.') {
                    l_point++;
                    i++;
                    continue;
                }

                if(! l_point)
                    lvalue *= 10;

                lvalue += (ch - '0') * pow(10, -l_point);
                i++;

                if(l_point)
                    l_point++;
            }

            while(i < temp.size() && (ch = temp.at(i), ! Isnum(ch))) {
                op += ch;
                type = 1;
                i++;
            }

            while(i < temp.size() && (ch = temp.at(i), Isnum(ch))) {
                if(ch == '.') {
                    r_point++;
                    i++;
                    continue;
                }

                if(! r_point)
                    rvalue *= 10;

                rvalue += (ch - '0') * pow(10, -r_point);
                i++;

                if(r_point)
                    r_point++;
            }

            Fun * f = new Fun(op, type, lvalue, rvalue);
            p->value = f->calc();
        }

        p = p->Next;
    }

    return head;
}
Node * Tree(Unit * head) { //���ɱ��ʽ��
    Node * root = NULL, * proot = NULL, * pbranch = NULL;
    Unit * p = head;
    int now_pri; //��ǰ���ȼ�
    bool hadop = false;

    while(p != NULL) {
        if(p->Type == 0) { //�����һ��������
            hadop = true;

            if(root == NULL) {
                proot = new Node(p->Operation, p->PRI, 1);
                root = proot;
                pbranch = root;
                now_pri = p->PRI;
                proot->Left = new Node(' ', 0, 0, p->Pre->value);
                proot->Right = new Node(' ', 0, 0, p->Next->value);
            } else {
                if(p->PRI < now_pri) { //���ȼ����ڵ�ǰ���ȼ�,��������
                    proot = new Node(p->Operation, p->PRI, 1); //�µ�����
                    proot->Left = root; //���ı任
                    proot->Left->Head = proot;
                    proot->Right = new Node(' ', 0, 0, p->Next->value);
                    proot->Right->Head = proot;
                    root = proot;
                    pbranch = proot; //����֦�ı任
//pbranch->Right=new Node(' ',0,0,p->Pre->value); //��֦�ұ�ȡֵ
                } else if(p->PRI == now_pri) { //���ȼ���ͬ,������ߵ�
                    Node * temp;
                    temp = new Node(p->Operation, p->PRI, 1);
                    temp->Left = pbranch;

                    if(pbranch->Head == NULL) {
                        proot = temp;
                        root = proot;
                        pbranch->Head = proot;
                    } else {
                        Node * temp0;
                        temp0 = pbranch->Head;
                        temp0->Right = temp;
                        temp->Head = temp0;
                        pbranch->Head = temp;
                    }

                    pbranch = temp;
                    pbranch->Right = new Node(' ', 0, 0, p->Next->value);
                    pbranch->Right->Head = pbranch;
                } else {
                    Node * temp;
                    temp = new Node(p->Operation, p->PRI, 1);
                    pbranch->Right = temp;
                    temp->Head = pbranch;
                    pbranch = pbranch->Right;
                    pbranch->Left = new Node(' ', 0, 0, p->Pre->value);
                    pbranch->Left->Head = pbranch;
                    pbranch->Right = new Node(' ', 0, 0, p->Next->value);
                    pbranch->Right->Head = pbranch;
                }

                now_pri = p->PRI;
            }
        }

        p = p->Next;
    }

    if(! hadop)
        root = new Node(' ', 0, 0, head->value);

    return root;
}
int main(void) {
    string exp;
	
	cout << "���׺���������" << endl;
	cout << "����˵��: " << endl << 
			"1: log����10Ϊ�׵Ĺ��̶���" << endl << 
			"2: ln ����eΪ�׵���Ȼ����" << endl << 
			"3: C ��������� ������� ����� 3ȡ2����� ������ʽ 3C2" << endl << 
			"4: A ���������� ������� ����� 3ȡ2������ ������ʽ 3A2" << endl << 
			"5: ! ����׳�" << endl << 
			"6: ^ x��y�η� ���� x^y" << endl;
	
    while(! getline(cin, exp).eof()) {
        if(exp == "")
            continue;

        Unit * h = Analyse(exp);
        h = Calc(h);
        Node * root = Tree(h);
        cout << exp << "=" << root->GetValue() << endl;
    }

    return 0;
}


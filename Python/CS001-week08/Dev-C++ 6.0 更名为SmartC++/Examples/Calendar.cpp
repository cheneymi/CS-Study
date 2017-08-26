#include <iostream>
#include <iomanip>
using namespace std;
class Calen {
private :
    int SpaceSize;                      // ������� setw()��С
    bool IsLeapYear(int year) {        // �ж��Ƿ�������
        return ((0 == year % 4 && 0 != year % 100) || (0 == year % 400));
    }
    int GetMonthDayNumber(int year , int month) {  //���� ĳһ��ĳһ������
        int daynumber ;

        if(2 == month) {					        //���µ�������
            if(IsLeapYear(year))
                daynumber = 29 ;
            else
                daynumber = 28 ;
        } else {
            if((month < 8  && 1 == month % 2) || (month >= 8 && 0 == month % 2))       //  ����ǰ������Ϊ31 �� ���º� ż��Ϊ 31 ��
                daynumber = 31 ;

            if((month < 8  && 0 == month % 2) || (month >= 8 && 1 == month % 2))       //  ����ǰż���� 30 ��  ���º� ������30 ��
                daynumber = 30 ;
        }

        return daynumber;
    }
public:
    int NowToDay(int year, int month , int day);				// ��ĳһ�쵽 1800 ��1 ��1 �� �ж�����
    bool InputDayIsTrue(int year , int month , int day);    // �ж�����������Ƿ�Ϸ�
    int FindDayWeekend(int year , int month , int day);     //����ĳһ�������ڼ�
    int DisplayMonth(int year , int month);				//��ʾĳһ���ĳһ�µ�����
    int DisplayYear(int year);							//��ʾĳһ�������
};

int main(void) {
    Calen calener;
    int year = 2013, month, day;

    if(true == calener.InputDayIsTrue(year, 1, 1)) {
        calener.DisplayYear(year);
    } else {
        cout << "The Input Day Is Error" << endl;
    }

    return 0;
}
int Calen :: NowToDay(int year, int month , int day) {
    int DiDay , i ;

    for(i = 1800 , DiDay = 0 ; i < year ; i++)   // ���� ����+ 366 ��
        if(IsLeapYear(i))
            DiDay += 366 ;
        else
            DiDay += 365 ;

    for(i = 1 ; i < month ; i++)
        DiDay += GetMonthDayNumber(year , i);

    DiDay += day - 1 ;

    return DiDay;
}
bool Calen :: InputDayIsTrue(int year , int month , int day) {
    int TureDayNumber ;

    if(year < 1800  ||  month > 13 || day > 31) {     // ������������С�� 1800 �� ���� 13 �� ����31 �� ���� ��
        return false;
    } else {
        TureDayNumber = GetMonthDayNumber(year, month);   // ��������day  �ȸ��µ�ʵ�� day �� ���ش���

        if(day > TureDayNumber)
            return false ;
    }

    return true;
}
int Calen ::DisplayMonth(int year, int month) {
    int  Excur ,  i , TotalDay  ;
    SpaceSize = 4 ;
    Excur = (NowToDay(year, month, 1) + 3) % 7 ;   // ���ȼ��� ����µ� 1 �� �����ڼ� Ȼ��������������Լ�����
    cout << year << "�� " << month << "��" << endl;

    cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "һ" << setw(SpaceSize) << "��" ;
    cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" ;
    cout << setw(SpaceSize) << "��" << endl;

    for(i = 1 ; i <= Excur ; i++)
        cout << setw(SpaceSize) << " "  ;     //������� ����Ŀո�

    TotalDay = GetMonthDayNumber(year , month);

    for(i = 1 ; i <= TotalDay ; i++) {   // Ȼ���Լӣ���Ȼ���ȴ����ߵ�ʱ����
        cout << setw(SpaceSize) << i ;

        if(0 == (i + Excur) % 7)         //��������
            cout << endl;
    }

    cout << endl ;
    return 0;
}
int Calen ::FindDayWeekend(int year , int month , int day) {  //����ĳһ�� �����ڼ�
    int TotalDay ;
    char Weekend[ 7 ][ 3 ] = {{"��"}, {"һ"}, {"��"}, {"��"}, {"��"}, {"��"}, {"��"} } ;
    TotalDay = NowToDay(year, month, day) ;
    cout << year << "�� " << month << "�� " << day << "�� ������" << Weekend[(TotalDay + 3) % 7 ] << endl;
    return 0;
}
int Calen ::DisplayYear(int year) {
    int    i , j, k , n , month1 , month2 , month3 ; // ���� һ��������� ���� month1 month2 month3 �� ����Ӧ��������
    int  Excur1 , Excur2 , Excur3 ;					//  i , j , k �ֱ��ʾ �����µ� ����ֵ  Excur1,Excur2,Excur3 ��ʾƫ����
    int  sea;
    char Months[12][10] = {{"һ��"}, {"����"}, {"����"}, {"����"}, {"����"}, {"����"}, {"����"}, {"����"}, {"����"}, {"ʮ��"}, {"ʮһ��"}, {"ʮ����"}};
    SpaceSize = 3 ;
    cout << year << " �� " << endl;

    for(sea = 1 ; sea <= 12 ; sea += 3) {              // ���ĸ�������ʾ
        Excur1 = (NowToDay(year, sea   , 1) + 3) % 7 ;     // �ֱ���� 3 ���µ�ƫ����
        Excur2 = (NowToDay(year, sea + 1 , 1) + 3) % 7 ;
        Excur3 = (NowToDay(year, sea + 2 , 1) + 3) % 7 ;
        month1 = GetMonthDayNumber(year , sea);          // �ֱ���� 3���µ� ����
        month2 = GetMonthDayNumber(year , sea + 1);
        month3 = GetMonthDayNumber(year , sea + 2);      //��ʾ�����µ� ����
        cout << Months[ sea - 1 ] << setw(21) << " " << Months[ sea ] << setw(20) << " " << Months[ sea + 1 ] << endl;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "һ" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << " ";

        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "һ" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << " ";

        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "һ" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" << setw(SpaceSize) << "��" ;
        cout << setw(SpaceSize) << "��" << endl;

        for(n = 1 ; n <= Excur1 ; n++)       // ��һ�� ��������  ������� ����Ŀո� Ȼ�����������
            cout << setw(SpaceSize) << " "  ;   // i ,j , k �������浱ǰ������

        for(n  ; n <= 7 ; n++)
            cout << setw(SpaceSize) << n - Excur1 ;

        cout << setw(SpaceSize) << " "  ;
        i =  n - Excur1 ;

        for(n = 1 ; n <= Excur2 ; n++)
            cout << setw(SpaceSize) << " "  ;

        for(n  ; n <= 7 ; n++)
            cout << setw(SpaceSize) << n - Excur2 ;

        cout << setw(SpaceSize) << " "  ;
        j = n - Excur2 ;

        for(n = 1 ; n <= Excur3 ; n++)
            cout << setw(SpaceSize) << " "  ;

        for(n  ; n <= 7 ; n++)
            cout << setw(SpaceSize) << n - Excur3 ;

        cout << endl ;
        k = n - Excur3 ;

        while(i <= month1 || j <= month2 || k <= month3) {    // �������µ����ڶ����� Ӧ�е�������  ѭ������
            for(n = i  ; i < n + 7; i++)                     // �������� 7 �����һ�Ρ����� ���������Ĳ�������ո�
                if(i <= month1)
                    cout << setw(SpaceSize) << i ;
                else
                    cout << setw(SpaceSize) << " " ;

            cout << setw(SpaceSize) << " " ;

            for(n = j  ; j < n + 7; j++)
                if(j <= month2)
                    cout << setw(SpaceSize) << j ;
                else
                    cout << setw(SpaceSize) << " " ;

            cout << setw(SpaceSize) << " " ;

            for(n = k  ; k < n + 7; k++)
                if(k <= month3)
                    cout << setw(SpaceSize) << k ;
                else
                    cout << setw(SpaceSize) << " " ;

            cout << endl;
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}


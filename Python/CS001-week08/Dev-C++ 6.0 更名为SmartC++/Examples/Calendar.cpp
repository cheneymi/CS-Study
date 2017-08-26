#include <iostream>
#include <iomanip>
using namespace std;
class Calen {
private :
    int SpaceSize;                      // 输出长度 setw()大小
    bool IsLeapYear(int year) {        // 判断是否是闰年
        return ((0 == year % 4 && 0 != year % 100) || (0 == year % 400));
    }
    int GetMonthDayNumber(int year , int month) {  //返回 某一年某一月天数
        int daynumber ;

        if(2 == month) {					        //二月单独处理
            if(IsLeapYear(year))
                daynumber = 29 ;
            else
                daynumber = 28 ;
        } else {
            if((month < 8  && 1 == month % 2) || (month >= 8 && 0 == month % 2))       //  八月前奇数月为31 天 八月后 偶数为 31 天
                daynumber = 31 ;

            if((month < 8  && 0 == month % 2) || (month >= 8 && 1 == month % 2))       //  八月前偶数月 30 天  八月后 奇数月30 天
                daynumber = 30 ;
        }

        return daynumber;
    }
public:
    int NowToDay(int year, int month , int day);				// 从某一天到 1800 年1 月1 日 有多少天
    bool InputDayIsTrue(int year , int month , int day);    // 判断输入的日期是否合法
    int FindDayWeekend(int year , int month , int day);     //查找某一天是星期几
    int DisplayMonth(int year , int month);				//显示某一年的某一月的日历
    int DisplayYear(int year);							//显示某一年的日历
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

    for(i = 1800 , DiDay = 0 ; i < year ; i++)   // 闰年 单独+ 366 天
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

    if(year < 1800  ||  month > 13 || day > 31) {     // 如果输入的日期小于 1800 年 大于 13 月 大于31 天 返回 假
        return false;
    } else {
        TureDayNumber = GetMonthDayNumber(year, month);   // 如果输入的day  比该月的实际 day 大 返回错误

        if(day > TureDayNumber)
            return false ;
    }

    return true;
}
int Calen ::DisplayMonth(int year, int month) {
    int  Excur ,  i , TotalDay  ;
    SpaceSize = 4 ;
    Excur = (NowToDay(year, month, 1) + 3) % 7 ;   // 首先计算 这个月的 1 日 是星期几 然后在这个基础上自加天数
    cout << year << "年 " << month << "月" << endl;

    cout << setw(SpaceSize) << "日" << setw(SpaceSize) << "一" << setw(SpaceSize) << "二" ;
    cout << setw(SpaceSize) << "三" << setw(SpaceSize) << "四" << setw(SpaceSize) << "五" ;
    cout << setw(SpaceSize) << "六" << endl;

    for(i = 1 ; i <= Excur ; i++)
        cout << setw(SpaceSize) << " "  ;     //首先输出 多余的空格

    TotalDay = GetMonthDayNumber(year , month);

    for(i = 1 ; i <= TotalDay ; i++) {   // 然后自加，当然长度大于七的时候换行
        cout << setw(SpaceSize) << i ;

        if(0 == (i + Excur) % 7)         //换行条件
            cout << endl;
    }

    cout << endl ;
    return 0;
}
int Calen ::FindDayWeekend(int year , int month , int day) {  //查找某一天 是星期几
    int TotalDay ;
    char Weekend[ 7 ][ 3 ] = {{"日"}, {"一"}, {"二"}, {"三"}, {"四"}, {"五"}, {"六"} } ;
    TotalDay = NowToDay(year, month, day) ;
    cout << year << "年 " << month << "月 " << day << "日 是星期" << Weekend[(TotalDay + 3) % 7 ] << endl;
    return 0;
}
int Calen ::DisplayYear(int year) {
    int    i , j, k , n , month1 , month2 , month3 ; // 按照 一个季度输出 日历 month1 month2 month3 是 该月应该有天数
    int  Excur1 , Excur2 , Excur3 ;					//  i , j , k 分别表示 三个月的 天数值  Excur1,Excur2,Excur3 表示偏移量
    int  sea;
    char Months[12][10] = {{"一月"}, {"二月"}, {"三月"}, {"四月"}, {"五月"}, {"六月"}, {"七月"}, {"八月"}, {"九月"}, {"十月"}, {"十一月"}, {"十二月"}};
    SpaceSize = 3 ;
    cout << year << " 年 " << endl;

    for(sea = 1 ; sea <= 12 ; sea += 3) {              // 分四个季度显示
        Excur1 = (NowToDay(year, sea   , 1) + 3) % 7 ;     // 分别计算 3 个月的偏移量
        Excur2 = (NowToDay(year, sea + 1 , 1) + 3) % 7 ;
        Excur3 = (NowToDay(year, sea + 2 , 1) + 3) % 7 ;
        month1 = GetMonthDayNumber(year , sea);          // 分别计算 3个月的 天数
        month2 = GetMonthDayNumber(year , sea + 1);
        month3 = GetMonthDayNumber(year , sea + 2);      //显示三个月的 星期
        cout << Months[ sea - 1 ] << setw(21) << " " << Months[ sea ] << setw(20) << " " << Months[ sea + 1 ] << endl;
        cout << setw(SpaceSize) << "日" << setw(SpaceSize) << "一" << setw(SpaceSize) << "二" ;
        cout << setw(SpaceSize) << "三" << setw(SpaceSize) << "四" << setw(SpaceSize) << "五" ;
        cout << setw(SpaceSize) << "六" << setw(SpaceSize) << " ";

        cout << setw(SpaceSize) << "日" << setw(SpaceSize) << "一" << setw(SpaceSize) << "二" ;
        cout << setw(SpaceSize) << "三" << setw(SpaceSize) << "四" << setw(SpaceSize) << "五" ;
        cout << setw(SpaceSize) << "六" << setw(SpaceSize) << " ";

        cout << setw(SpaceSize) << "日" << setw(SpaceSize) << "一" << setw(SpaceSize) << "二" ;
        cout << setw(SpaceSize) << "三" << setw(SpaceSize) << "四" << setw(SpaceSize) << "五" ;
        cout << setw(SpaceSize) << "六" << endl;

        for(n = 1 ; n <= Excur1 ; n++)       // 第一行 单独处理  首先输出 多余的空格 然后在输出天数
            cout << setw(SpaceSize) << " "  ;   // i ,j , k 单独保存当前的日期

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

        while(i <= month1 || j <= month2 || k <= month3) {    // 当三个月的日期都大于 应有的天数后  循环结束
            for(n = i  ; i < n + 7; i++)                     // 接下来的 7 天输出一次。但是 大于天数的部分输出空格
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



#include <iostream>
#include <Windows.h>


int main(){
    //声明变量
    SYSTEMTIME sys_time;

    //将变量值设置为本地时间
    GetLocalTime( &sys_time );

    //输出时间
    printf( "%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n",sys_time.wYear,
        sys_time.wMonth,
        sys_time.wDay,
        sys_time.wHour,
        sys_time.wMinute,
        sys_time.wSecond,
        sys_time.wMilliseconds,
        sys_time.wDayOfWeek);

    system("time");

    system("pause");
    return 0;
}

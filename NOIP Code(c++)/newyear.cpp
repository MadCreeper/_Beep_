
#include <iostream>
#include <Windows.h>


int main(){
    //��������
    SYSTEMTIME sys_time;

    //������ֵ����Ϊ����ʱ��
    GetLocalTime( &sys_time );

    //���ʱ��
    printf( "%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d\n",sys_time.wYear,
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

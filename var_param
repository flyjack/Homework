//可变参数API使用方法，适用于记录日志的场景

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//struct tm 定义的地方，不是sys/time.h
#include <time.h>

//注意后面是三个点
void fun(char *fmt, ...)
{
    char str[100] = {'\0'};
    char format[100] = {'\0'};

    struct tm t_tm;
    time_t timer;
    time(&timer);
    localtime_r(&timer, &t_tm);

    //snprintf(format, 100, "%04d-%02d-%02d %02d:%02d:%02d, %s\n", t_tm.tm_year + 1900, t_tm.tm_mon + 1, t_tm.tm_mday, t_tm.tm_hour, t_tm.tm_min, t_tm.tm_sec, fmt);

    va_list args;
    va_start(args, fmt);

    //vsnprintf 接受可变参数
    vsnprintf(str, 100, fmt, args);
    //vsnprintf(str, 100, format, args);
    va_end(args);

    printf("%s\n", str);
}

int main()
{
    fun("%d %f %s\n", 4, 5.4, "hello world");

    return 0;
}

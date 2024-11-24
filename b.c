/* ************************************************************************
> File Name:     b.c
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Sat 23 Nov 2024 10:29:09 PM CST
> Description:   
 ************************************************************************/

#include <stdio.h>

#define LOG_DEBUG(fmt, ...)             \
        printf("[DEBUG]:[%s-line:%d]: "fmt, __FILE__, __LINE__, ##__VA_ARGS__)

int main(){

    LOG_DEBUG("hello world\n");
    return 0;
}

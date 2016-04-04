//
// Created by wshh08 on 16-3-27.
//

/******************************************/
/*
 * 数组指针学习相关代码片段
 *
 * 对指针进行加1操作，得到的是下一个元素的地址，而不是原有地址值直接加1。
 * 所以，一个类型为T的指针的移动，以sizeof(T)为移动单位。
 * 因此，对以下代码来说，a是一个一维数组，数组中有5个元素，所以a的类型是数组指针；
 * ptr是一个int型的指针，ptr的类型是整型指针。
 * a,&a的值是一样的，但意思不一样，a是数组首元素的首地址，也就是a[0]的首地址，&a是数组的首地址，
 * a+1是数组下一元素的首地址，即a[1]的首地址,&a+1是下一个数组的首地址。
 *
 */
#include <stdio.h>
int main()
{
    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);
    printf("&a和a值都是: %x\n", (unsigned)&a);
    printf("a+1结果为: %x\n", (unsigned)(a+1));
    printf("&a+1结果为: %x\n", (unsigned)(&a+1));
    printf("%d, %d \n",*(a+1),*(ptr-1));
    return 0;
}


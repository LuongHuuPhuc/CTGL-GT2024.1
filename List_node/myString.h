#ifndef MYSTRING_H
#define MYSTRING_H

#include<stdio.h>
#include<stdlib.h>

//So Sanh 2 Chuoi
int soSanhChuoi(char *str1, char *str2);

//Copy chuoi nguon toi chuoi dich
void copyChuoi(char *chuoiDich, const char *chuoiNguon);

//Tim nhung phan tu o chuoi 1 ma chuoi 2 khong co
int doDaiChuoi(const char *str1, char ch);

#endif // MYSTRING_H
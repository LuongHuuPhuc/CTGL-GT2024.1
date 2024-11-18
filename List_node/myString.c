//Xu ly phan chuoi dau vao
/*Dinh nghia ham file myString.c */
//Khai bao thu vien can dung
#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

//So sanh 2 chuoi
int soSanhChuoi(char *str1, char *str2){ //strcmp()
    while(*str1 && (*str1 == *str2)){ //Lap cho den khi gap ky tu null hoac ky tu khac nhau
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2; //So sanh ky tu cuoi cung khac nhau
    /*Tra ve 0 neu 2 chuoi bang nhau
    Tra ve gia tri duong neu str1 > str2 
    Tra ve gia tri am neu str1 < str2*/
}

//Copy chuoi 
void copyChuoi(char *chuoiDich, const char *chuoiNguon){ //strcpy()
    while(*chuoiNguon){//Lap qua tung ky tu cua chuoi nguon cho den khi gap null \0
        *chuoiDich = *chuoiNguon++; //gan ky tu tu nguon sang dich va tang con tro
    }
    *chuoiDich = '\0';
}

//Tim do dai ky tu cua chuoi 1 ma khong chua cac ky tu cua chuoi 2
int doDaiChuoi(const char *str1, char ch){ //strcspn()
    int count = 0;
    while(*str1){//Duyet qua tung ky tu cua str1 cho den khi gap null
    if(*str1 == ch) return count;
    str1++;
    count++;
    }
    return count; //Neu khong tim thay thi tra ve do dai bang voi do dai str1
}
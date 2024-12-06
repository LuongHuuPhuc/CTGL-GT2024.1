#ifndef NHAP_XUAT_STACK_H
#define NHAP_XUAT_STACK_H

#include<iostream>
#define MAXSIZE 100

struct Stack{
    int data[MAXSIZE]; //Mang luu tru cac phan tu cua ngan xep
    int top; //Chi so cua phan tu tren dinh ngan xep
}; 

//Ham khoi tao Stack
void khoiTaoStack(Stack &stack);

//Kiem tra stack day
bool ktrStackDay(const Stack &stack);

//Kiem tra stack rong
bool ktrStackRong(const Stack &stack);

//Them phan tu vao ngan xep
void push(const Stack &stack, int value);

//Xoa phan tu khoi ngan xep
int pop(const Stack &stack);

//Ham nhap phan tu vao ngan xep
void nhapStack(const Stack &stack);

//Ham xuat ngan xep
void xuatStack(const Stack &stack);

//Ham in ra ngan xep
void inNganXep(const Stack &stack);

#endif //NHAP_XUAT_STACK_H


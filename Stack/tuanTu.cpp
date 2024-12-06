#include<iostream>
#include "inc/nhapXuatStack.h"
#define MAXSIZE 100 //Kich thuoc toi da cua ngan xep

//Cau truc cua Stack
/*struct Stack{
    int data[MAXSIZE]; //Mang luu tru cac phan tu cua ngan xep
    int top; //Chi so cua phan tu tren dinh ngan xep
}; */

//Ham khoi tao ngan xep
/*void khoiTaoStack(Stack &stack){
    stack.top = -1; //Ngan xep ban dau rong, top = -1
}

//Kiem tra xem ngan xep co rong hay khong
bool ktrStackRong(const Stack &stack){
    return stack.top == -1;
}

//Kiem tra xem ngan xep co day hay khong
bool ktrStackDay(const Stack &stack){
    return stack.top == MAXSIZE - 1;
}

//Them phan tu vao ngan xeo
void push(Stack &stack, int value){
    if(ktrStackDay(stack)){
        std::cout << "Ngan xep da day, khong the them phan tu !" << std::endl;
        return;
    }
    stack.data[++stack.top] = value; //tang top va them phan tu
}

//Xoa phan tu khoi ngan xep
int pop(Stack &stack){
    if(ktrStackRong(stack)){
        std::cout << "Ngan xep rong, khong the xoa phan tu !" << std::endl;
        return -1;
    }
    return stack.data[stack.top--]; //Lay phan tu tren dinh va giam top
}

//Lay gia tri phan tu tren dinh ngan xep
int top(const Stack &stack){
    if(ktrStackRong(stack)){
        std::cout << "Ngan xep rong, khong co phan tu tren dinh !" << std::endl;
        return -1;
    }
    return stack.data[stack.top];
}

//In ra cac phan tu trong ngan xep
void inNganXep(const Stack &stack){
    if(ktrStackRong(stack)){
        std::cout << "Ngan xep rong !" << std::endl;
        return;
    }
    std::cout << "Cac phan tu trong ngan xep: " ;
    for(int i = 0; i <= stack.top; i++){
        std::cout << stack.data[i] << " ";
    }
    std::cout << std::endl;
}
*/
int main(){
    Stack stack;
    khoiTaoStack(stack);

    //Thuc hien cac thao tac tren ngan xep
    /*push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    inNganXep(stack);

    std::cout << "Phan tu tren dinh ngan xep la: " << top(stack) << std::endl;

    std::cout << "Xoa phan tu trong ngan xep: " << pop(stack) << std::endl;

    //In ra ngan xep sau khi xoa cac phan tu 
    inNganXep(stack);*/

    //Them phan tu vao ngan xep
    nhapStack(stack);

    //In ra ngan xep
    inNganXep(stack);

    //Xuat ra ngan xep theo thu tu LIFO
    xuatStack(stack);

    return 0;   
}
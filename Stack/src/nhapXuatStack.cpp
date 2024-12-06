#include<iostream>
#define MAXSIZE 100
using namespace std;

//Cau truc stack
struct Stack{
    int data[MAXSIZE];
    int top;
}; 

//Khoi tao Stack
void khoiTaoStack(Stack &stack){
    stack.top = -1; //Ngan xep ban dau la -1
}

//Kiem tra ngan xep co day khong
bool ktrStackDay(const Stack &stack){
    return stack.top == MAXSIZE - 1;
}

//Kiem tra ngan xep co rong khong
bool ktrStackRong(const Stack &stack){
    return stack.top == -1;
}

//Them phan tu vao ngan xep
void push(const Stack &stack, int value){
    if(ktrStackDay(stack)){
        cout << "Ngan xep da day, khong the them vao ngan xep !" << endl;
        return;
    }
    stack.data[++stack.top] = value;
}

//Xoa phan tu ra khoi ngan xep
int pop(const Stack &stack){
    if(ktrStackRong(stack)){
        cout << "Ngan xep rong, khong the xoa phan tu !" << endl;
        return -1;
    }
    return stack.data[stack.top--];
}

//Nhap du lieu vao ngan xep
void nhapStack(const Stack &stack){
    int n, value;
    cout << "Nhap so luong phan tu vao ngan xep: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Phan tu thu " << i + 1 << " la: ";
        cin >> value; 
        push(stack, value);
    }
}

//Ham xuat ngan xep
void xuatStack(const Stack &stack){
    cout << "Xuat cac phan trong ngan xep (LIFO - Last In First Out): " ;
    while(!ktrStackRong(stack)){
        cout << "Cac phan tu xuat ra la: " << pop(stack) << " ";
    }
    cout << endl;
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
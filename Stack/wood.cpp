#include<iostream>
#include<string>
#define MAXSIZE 100
using namespace std;

//Cau truc go
typedef struct Wood{
    int sizeGo ;
    string loaiGo;
    int age;
} go; 

//Cau truc Stack 
struct Stack{
    go data[MAXSIZE];
    int top;
};

//Khoi tao danh sach rong 
void khoiTaoStack(Stack &stack){
        
}

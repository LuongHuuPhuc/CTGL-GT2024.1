#include<stdio.h>
#include<stdlib.h>

//Ham in ra nam khong co nguoi nao duoc sinh ra
void nhapSoLieu(int *N, int size){
    for(int i = 0; i < size; i++){
        printf("Nhap so luong nguoi sinh ra trong nam %d ", 1920 + i );
        scanf("%d ", &N[i]);
    }
}

//Ham in ra nam khong co ai sinh ra
void inNamKhongCoNguoiSinh(int *N, int size){
    printf("Nhung nam khong co nguoi sinh la: ");
    for(int i = 0; i < size; i++){
        if(N[i] == 0){
            printf("%d ", 1920 + i);
        }
    }
    printf("\n");
}

//Ham in ra nam ma so nguoi sinh ra khong qua 10
void khongQuaMuoi(int *N, int size){
    int count = 0;
    for(int i =0; i < size; i++){
        if(N[i] <= 10){
            count++;
        }
    }
    printf("Nhung nam ma so nguoi sinh ra khong qua 10 la: %d ", count);
}

void tinhSoNguoiTren50Tuoi(int *N, int size){
    int total = 0;
    //Kiem tra nhung nam truoc 1935 (tuong ung index 0 den 15)
    for(int i = 0; i <= 15; i++){
        total += N[i];
    }
    printf("\nSo nguoi da tren 50 tuoi tinh den nam 1985: %d ", total);
    printf("\n");
}
int main(){
    int size = 1970 - 1920 + 1;
    //Nhap so người của các năm từ bàn phím
    int *Year = (int*)malloc(size * sizeof(int)); //Cap phat dong cho mang

    if( Year == NULL){
        printf("Cap phat mang dong khong thanh cong ");
        return 1;
    }

    nhapSoLieu(Year, size);
    inNamKhongCoNguoiSinh(Year, size);
    khongQuaMuoi(Year, size);
    tinhSoNguoiTren50Tuoi(Year, size);

    //Giai phong bo nho 
    free(Year);
    return 0;

}
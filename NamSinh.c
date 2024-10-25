#include<stdio.h>
#include<stdlib.h>

//Ham in ra nam khong co nguoi nao duoc sinh ra
void nhapSoLieu(int *year, int size){
    for(int i = 0; i < size; i++){
        printf("Nhap so luong nguoi sinh ra trong nam %d ", 1920 + i );
        scanf("%d ", &year[i]);
    }
}

//Ham in ra nam khong co ai sinh ra
void inNamKhongCoNguoiSinh(int *year, int size){
    printf("Nhung nam khong co nguoi sinh la: ");
    for(int i = 0; i < size; i++){
        if(year[i] == 0){
            printf("%d ", 1920 + i);
        }
    }
    printf("\n");
}

//Ham in ra nam ma so nguoi sinh ra khong qua 10
void khongQuaMuoi(int *year, int size){
    int count = 0;
    for(int i =0; i < size; i++){
        if(year[i <= 10]){
            count++;
        }
    }
    printf("Nhung nam ma so nguoi sinh ra khong qua 10 la: %d ", count);
}

void tinhSoNguoiTren50Tuoi(int *year, int size){
    int total = 0;
    for(int i = 0; i <= 15; i++){
        total += n[i];
    }
    printf("So nguoi da tren 50 tuoi tinh den nam 1985: %d ", total);
    printf("\n");
}
int main(){
    int size = 1970 - 1920 + 1;
    int *Year = (int*)malloc(size * sizeof(int)); //Cap phat dong cho mang

    if( Year == NULL){
        printf("Cap phat mang dong khong thanh cong ");
        return 1;
    }

    nhapSoLieu(Year, size);

}
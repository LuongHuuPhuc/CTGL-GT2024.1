#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

//Khai bao cau truc du lieu 
//Dinh nghia cau truc Ngay de luu tru ngay, thang, nam
typedef struct Ngay{
    int ngay, thang, nam;
} Ngay;

//Tao kieu du lieu SinhVien gom cac thong tin cua sinh vien
typedef struct{
    char maSV[8];
    char hoTen[50];
    int gioiTinh; //0: Nu, 1: Nam
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
}SinhVien;

//Khai bao cau truc cua 1 Node cua danh sach lien ket don 
typedef struct Node{
    SinhVien data; //Tóm gọn các thông tin cua sinh vien bằng biến data - luu tru thong tin cua node
    struct Node *link; //Chua dia chi cua phan tu/node tiep theo 
}Node;

//Dinh nghia cau truc Lisr chua danh sach sinh vien 
typedef struct {
    Node *first; //Con tro den node dau tien cua danh sach
    Node *last; //Con tro den node cuoi cung cua danh sach
}List;

//Khoi tao danh sach rong
void khoiTaoDanhSach(List *list){
    list->first = NULL; // toan tu arrow -> de truy cap thanh vien cua 1 struct
    list->last = NULL;
}

//Ham them sinh vien moi vao danh sach theo thu tu
//Tao node moi chua thong tin sinh vien
Node *taoNode(SinhVien sv){
    //Cap phat bo nho dong cho 1 Node moi 
    Node *newNodes = (Node*)malloc(sizeof(Node)); //Cap phat mang dong
    if(newNodes == NULL){
        printf("Cap phat dong khong thanh cong - Khong du bo nho ! \n");
        exit(1); //Thoat chuong trinh neu khong du bo nho
    }
    newNodes -> data = sv; //Gan thong tin sinh vien vao data cua node
    newNodes -> link = NULL; //Node moi se khong tro toi node nao
    return newNodes;
}

//Ham chen sinh vien vao danh sach theo thu tu ma sinh vien
void insertedSorted(List *list, SinhVien sv){
    Node *newNode = taoNode(sv); //Tao node moi voi thong tin sinh vien 

    //Neu danh sach rong, them node moi vao dau danh sach 
    if(list -> first == NULL){
        list -> first = newNode;
        list -> last = newNode;
    }
    else{
        Node *truoc = NULL;
        Node *hientai = list -> first;

        //Tim vi tri thich hop de chen dua theo ma sinh vien
        while(hientai != NULL && soSanhChuoi(hientai->data.maSV, sv.maSV) < 0){
            truoc = hientai;
            hientai = hientai -> link;
        }

        //Chen vao dau danh sach neu node truoc do bang NULL
        if(truoc == NULL){
            newNode->link = list->first;
            list->first = newNode;
        }

        //Chen vao giua hoac cuoi danh sach
        else{
            truoc->link = newNode;
            newNode->link = hientai;
            if(hientai == NULL){
                list->last = newNode;
            }
        }
    }
}


//Ham in ra danh sach sinh vien 
void printList(List list){
    Node *p = list.first;
    while(p != NULL){ //Duyet qua tung node cua danh sach 
        printf("Ma SV: %s \nHo Ten: %s \nGioi tinh: %s \nNgay Sinh: %d/%d/%d  \nDia chi: %s \nLop: %s \nKhoa: %s \n",
        p->data.maSV, 
        p->data.hoTen, 
        p->data.gioiTinh, 
        p->data.ngaySinh.ngay,
        p->data.ngaySinh.thang, 
        p->data.ngaySinh.nam, 
        p->data.diaChi, 
        p->data.lop, 
        p->data.khoa);
        p = p->link;
    }

}

//Ham in sinh vien co cung ngay sinh
void inSinhVienCungNgaySinh(List list, Ngay NgaySinh){
    Node *p = list.first;
    int found = 0; //Bien kiem tra xem co tim thay sinh vien cung ngay sinh khong 
    while(p != NULL){
        if(p->data.ngaySinh.ngay == NgaySinh.ngay && 
        p->data.ngaySinh.thang == NgaySinh.thang &&
        p->data.ngaySinh.nam == NgaySinh.nam){
            printf("Ma SV: %s \nHo Ten: %s \n", p->data.maSV, p->data.hoTen);
            found = 1;
        }
        p = p->link;
    }
    if(!found){ //Neu khong tim thay sinh vien 
        printf("Khong tim thay sinh vien co cung ngay sinh! \n");
    }
}

//Ham xoa sinh vien co cung ngay sinh 
void xoaSVCungNgaySinh(List *list, Ngay ngaySinh){
    Node *truoc = NULL;
    Node *hientai = list->first;

    while (hientai != NULL){
        if(hientai->data.ngaySinh.ngay == ngaySinh.ngay &&
        hientai->data.ngaySinh.thang == ngaySinh.thang &&
        hientai->data.ngaySinh.nam == ngaySinh.nam){

            //Xoa Node dau 
            if(truoc == NULL){
                list->first = hientai->link;
            }
            else{
                truoc->link = hientai->link;
            }
            //Neu la nut cuoi cung
            if(hientai == list->last){
                list->last = truoc;
            }
            free(hientai); //Giai phong bo nho cua node 
            hientai = (truoc == NULL) ? list->first : truoc->link;
        }
        else{

        }
    }
}

void nhapThongTin(SinhVien *sv){
    printf("Nhap ma SV: ");
    scanf("%s", sv->maSV);
    printf("Nhap ho ten: ");
    getchar(); //Loai bo ky tu xuong dong, cho phép nhận 1 ký tự từ stdin và trả về ký tự đó
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin); //Nhận chuỗi từ stdin, kết thúc khi lấy đủ dữ liệu hoặc gặp dấu enter (NULL,\0)
    sv->hoTen[doDaiChuoi(sv->hoTen, '\n')] = '\0'; //So sanh xem co ky tu 
    printf("Nhap gioi tinh (0: Nu, 1: Nam): ");
    scanf("%d", &sv->gioiTinh);
    printf("Nhap ngay sinh (Ngay - Thang - Nam): ");
    scanf("%d %d %d ", &sv->ngaySinh.ngay, &sv->ngaySinh.thang, &sv->ngaySinh.nam);
    printf("Nhap dia chi: ");
    getchar(); //Loai bo ky tu enter cua truoc do
    fgets(sv->diaChi, sizeof(sv->diaChi), stdin);
    sv->diaChi[doDaiChuoi(sv->diaChi, '\n')] = '\0'; //Xoa ky tu \n
    printf("Nhap lop: ");
    scanf("%s", sv->lop);
    printf("Nhap khoa: ");
    scanf("%s", sv->khoa);
}

//Chuong trinh chinh
int main(){
    List list;
    khoiTaoDanhSach(&list); //Khoi tao danh sach rong

    int n, cheDo;
    Ngay ngaySinh;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        SinhVien sv;
        printf("\nNhap thong tin sinh vien thu %d :\n", i + 1);
        nhapThongTin(&sv);
        insertedSorted(&list, sv);

    }

    printf("\n--- Chon che do ban muon ---\n");
    printf("1. Xem danh sach sinh vien\n");
    printf("2. Danh sach sinh vien co cung ngay sinh\n");
    printf("3. Loai bo cac sinh vien co cung ngay sinh");

    printf("\nVui long nhap che do muon xem: ");
    scanf("%d", &cheDo);

    switch (cheDo)
    {
    case 1:
    printf("\nDanh sach sinh vien: \n");
    printList(list);
    break;

    case 2: 
    printf("\nHay nhap ngay-thang-nam can tim: ");
    scanf("%d %d %d", &ngaySinh.ngay, &ngaySinh.thang, &ngaySinh.nam);
    inSinhVienCungNgaySinh(list, ngaySinh);
    break;

    case 3:
    printf("Hap nhap ngay-thang-nam muon xoa: ");
    scanf("%d %d %d", &ngaySinh.ngay, &ngaySinh.thang, &ngaySinh.nam);
    xoaSVCungNgaySinh(&list, ngaySinh);
    printf("\nDanh sach sinh vien sau khi xoa:\n ");
    printList(list);
    break;

    default: 
    exit(1); //Neu khong chon 1 trong 3 che do 
    break;
    }

    return 0;
}
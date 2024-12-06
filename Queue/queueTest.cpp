#include <iostream>
#include <string>
using namespace std;

//Cau truc cua San Pham 
struct SanPham{
    string name;
    int soLuong;
    int giaSp;
};

//Cau truc Gio Hang, tuong duong voi 1 Node
struct gioHang{
    string customerName; //Ten khach hang
    int soLuongSp; //So luong san pham 
    SanPham *sanpham; //Mang cac san pham
    gioHang *next; //Con tro toi node ke tiep
};

//Cau truc hang doi queue
struct queue{
    gioHang *front; //Xoa phan tu trong hang doi, luon dien ra o dau hang (front)
    gioHang *rear; //Them phan tu vao hang doi, luon dien ra o cuoi hang (rear)
};

//Ham tao hang doi 
void khoiTaoQueue(queue &q){
    q.front = q.rear = nullptr;
}

//Ham kiem tra hang doi rong
bool ktrQueueRong(queue q){
    return (q.front == nullptr);
}

//Ham them khach hang vao hang doi 
void enQueue(queue &q, string customerName, int soLuongSp, SanPham *sanpham){
    gioHang *newNode = new gioHang;
    newNode-> customerName = customerName;
    newNode->soLuongSp = soLuongSp;
    newNode->sanpham = sanpham;
    newNode->next = nullptr;

    if(ktrQueueRong(q)){
        q.front = q.rear = newNode;
    }else{
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

//Ham loai bo khach hang da thanh toan (dequeue)
void deQueue(queue &q){
    if(ktrQueueRong(q)){
        cout << "Hang doi rong, khong co ai de xoa. \n";
        return;
    }

    gioHang *temp = q.front;
    q.front = q.front->next;

    if(q.front == nullptr){
        q.rear = nullptr; //Hang doi rong 
    }

    //delete[] temp->sanpham; //Xoa mang san pham
    delete temp; //Xoa Node
}


//Ham tinh tong tien thu ngan thu duoc
double tongSoTienThu(queue q){
    double tongThu = 0.0;

    gioHang *current = q.front;
    while(current != nullptr){
        for(int i = 0; i < current->soLuongSp; i++){
            tongThu += current->sanpham[i].soLuong * current->sanpham[i].giaSp;
        }
        current = current->next;
    }
    return tongThu;
}

//Ham dem so luong san pham A nao do da ban
int demSanPhamDaBan(queue q, string tenSanPham){
    int count = 0;

    gioHang *current = q.front;
    while(current != nullptr){
        for(int i = 0; i < current->soLuongSp; i++){
            if(current->sanpham[i].name == tenSanPham){
                count += current->sanpham[i].soLuong;
            }
        }
        current = current->next;
    }
    return count;
}

//Ham hien thi hang doi (chi de kiem tra)
void hienThiHangDoi(queue q){
    if(q.front == nullptr){
        cout << "Hang doi dang rong !" << endl;
        return;
    }

    gioHang *current = q.front;
    cout << "Cac khach hang dang trong hang doi: " << endl;
    while(current != nullptr){
        cout << "Khach hang: " << current->customerName << "\n";
        for(int i = 0; i < current->soLuongSp; i++){
            cout << "- " << current->sanpham[i].name << "(x" << current->sanpham[i].soLuong << ", " << current->sanpham[i].giaSp << "vnd)\n";
        }
        current = current->next;
        cout << endl;
    }
}

int main(){
    queue hangDoi;
    khoiTaoQueue(hangDoi);

    //Tao cac gio hang
    /*SanPham gio1[] = {{"Apple", 3, 20000}, {"Milk", 2, 15000}};
    SanPham gio2[] = {{"Bread", 1, 12000}, {"Butter", 5, 20000}};
    SanPham gio3[] = {{"Grape", 2, 30000}, {"Coca", 3, 10000}};

    //Them khach hang vao hang doi
    enQueue(hangDoi, "Customer 1: ", 2, gio1);
    enQueue(hangDoi, "Customer 2: ", 2, gio2);
    enQueue(hangDoi, "Customer 3: ", 2, gio3);

    //Hien thi hang doi ban dau
    cout << "Hang doi ban dau: \n";
    hienThiHangDoi(hangDoi);

    //Tinh tong tien tai thu ngan
    cout << "Tong so tien thu duoc: " << tongSoTienThu(hangDoi) << " vnd\n";

    //Dem so luong san pham "Apple"
    cout << "So luong san pham \"Tao\" da ban: " << demSanPhamDaBan(hangDoi, "Apple") << endl;

    //Loai bo khach hang da thanh toan
    cout << "\n Loai bo khach hang dau tien...\n";
    deQueue(hangDoi);

    //Hien thi hang doi sau khi loai bo
    cout << "Hang doi sau khi duoc loai bo: \n";
    hienThiHangDoi(hangDoi);

    return 0; */
    int soLuongKhach;
    
}
#include <iostream>
#include <string.h>

using namespace std;

/**
 * @param Ace Anh chi em 
 */

struct Node {
    string title; //Tieu de
    int pageCount; //So trang
    Node *firstCon; //con dau tien
    Node *nextAce; //Anh chi em ke tiep
};
    //Khoi tao Node 
Node *nodeInit(string t, int p){
    Node *newNode = new Node();
    newNode->title = t;
    newNode->pageCount = p;
    newNode->firstCon = nullptr;
    newNode->nextAce = nullptr;
    return newNode;
}

//Ham them mot muc con vao mot nut cha
void addCon(Node *cha, Node *con){
    if(!cha->firstCon){
        cha->firstCon = con; //Gan muc con dau tien neu chua co   
    }else{
        Node *Ace = cha->firstCon;
        while(Ace->nextAce){//Duyet qua danh sach anh chi em
            Ace = Ace->nextAce; 
        }
        Ace->nextAce = con; //Luu gia tri cua anh chi em vao con tro next
    }
}

//Ham dem so chuong trong sach (Chapter = cac muc con truc tiep cua root)
int demChapters(Node *root){
    if(!root){
        return 0;
    }
    int count = 0; //Bien dem so chuong 
    Node *con = root->firstCon;
    while(con){
        count++;
        con = con->nextAce;
    }
    return count;
}

//Ham de quy tinh tong so trang cua mot muc
int tinhTongTrang(Node *node){
    if(!node){
        return 0;
    }
    int tongTrang = node->pageCount;
    Node *con = node->firstCon;
    while(con){
        tongTrang += tinhTongTrang(con);
        con = con->nextAce;
    }
    return tongTrang;
}

//Ham tim chapter dai nhat
Node *timChapDaiNhat(Node *root){
    if(!root){
        return 0;
    }
    Node *chuongDaiNhat = nullptr;
    int maxTrang =0;

    Node *con = root->firstCon;
    while(con){
        int trangTrongMotChap = tinhTongTrang(con);
        if(trangTrongMotChap > maxTrang){
            maxTrang = trangTrongMotChap;
            chuongDaiNhat = con;
        }
        con = con->nextAce;
    }
    return chuongDaiNhat;
}

//Tim va xoa muc khoi cay
bool timVaXoa(Node *root, const string &title){
    if(!root){
        return false;
    }

    Node *con = root->firstCon; //Tao con tro con = con tro goc tro toi con dau tien
    Node *truoc = nullptr; //Mac dinh muc truoc do la khong ton tai

    while(con){
        if(con->title == title){
            if(truoc){
                truoc->nextAce = con->nextAce; //Noi muc truoc voi muc sau
            }else{
                root->firstCon = con->nextAce; //Cap nhat con dau tien neu xoa con dau
            }
            delete con; //Xoa muc khoi bo nho
            return true;
        }else{
            if(timVaXoa(con, title)){
                return true; //Tim trong muc con
            }
        }
        truoc = con;
        con = con->nextAce;
    }
    return false; //Khong tim thay =))
}

//Ham cap nhat so trang cua mot muc sau khi xoa
void capNhatTrang(Node *root){
    if(!root){
        return;
    }
    root->pageCount = 0;
    Node *con = root->firstCon;
    while(con){
        capNhatTrang(con);
        root->pageCount += con->pageCount; //Cong don so trang tu cac muc con
        con = con->nextAce;
    }
}

//Ham in cau truc cay theo dang lui dong
void inCay(Node *root, int thutLe = 0){
    if(!root){
        return;
    }

    for(int i = 0; i < thutLe; i++){
        cout << " ";
    }
    cout << root->title << " (" << root->pageCount << "trang) " << endl;
    Node *con = con->firstCon;
    while(con){
        inCay(con, thutLe + 1);
        con = con->nextAce;
    }
}

int main(){
    //Tao goc cua cay
    Node *root = nodeInit("Node", 0);

    //Them cac chuong (Chapter)
    Node *chapter1 = nodeInit("CHAPTER1", 10);
    Node *chapter2 = nodeInit("CHAPTER2", 20);
    Node *chapter3 = nodeInit("CHAPTER3", 15);

    //Them cac muc con (Section, Subsection)
    Node *section1_1 = nodeInit("section1_1", 5);
    Node *section1_2 = nodeInit("section1_2", 3);
    addCon(chapter1, section1_1);
    addCon(chapter1, section1_2);

    Node *section2_1 = nodeInit("section2_1", 10);
    Node *section2_2 = nodeInit("section2_2", 8);
    addCon(chapter2, section2_1);
    addCon(chapter2, section2_2);

    addCon(root, chapter1);
    addCon(root, chapter2);
    addCon(root, chapter3);

    //Dem so chuong 
    cout << "So chuong: " << demChapters(root) << endl; 

    //Tim chuong dai nhat 
    Node *chapDaiNhat = timChapDaiNhat(root);
    if(chapDaiNhat){
        cout << "Chuong dai nhat: " << chapDaiNhat->title << " (" << tinhTongTrang(chapDaiNhat) << " trang)" << endl;
    }

    //Xoa muc "section2_1"
    if(timVaXoa(root, "section2_1")){
        cout << "Da xoa section2_1 "  << endl;
        capNhatTrang(root); 
    }

    //In cau truc cay
    cout << "Cau truc cay sau khi xoa: " << endl;
    inCay(root);

    return 0;
}
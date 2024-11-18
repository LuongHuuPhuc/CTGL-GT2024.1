#include<iostream>
#include<string>

#define MAXSIZE 32000
using namespace std;

//Dinh nghia cau truc Node de luu tru thong tin file
struct Node{
    string fileName;
    int fileSize; //MB
    int timeStamp; 
    Node *next;
};

//Ham tao mot Node moi
Node *taoNode(const string &fileName, int fileSize, int timeStamp){
    Node *newNode = new Node(); //Cap bo nho cho mot Node moi
    newNode->fileName = fileName; //Dat ten file cho Node
    newNode->fileSize = fileSize; //Dat kich thuoc file cho Node
    newNode->timeStamp = timeStamp; //dat thoi gian cho file
    newNode->next = nullptr; //Khoi tao con tro next la nullprt 
    return newNode;
}

//Ham chen file vao danh sach treo trat tu thoi gian 
void insertFile(Node *&head, const string &fileName, int fileSize, int time){
    Node *newNode = taoNode(fileName, fileSize, time);
//Chen vao dau neu danh sach rong hoac thoi gian cua node moi nho hon node dau
    if(!head || head->timeStamp > time){
        newNode->next = head;
        head = newNode;
    }else{
        //Duyet qua danh sach de tim vi tri chen
        Node *current = head;
        //Duyet qua danh sach de tim vi tri thich hop
        while(current->next != nullptr && current->next->timeStamp <= time){
            current  = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Ham tinh tong kich thuoc cua tat ca cac file trong danh sach 
int tongSizeFile(Node *head){
    int totalSize = 0;
    Node *current = head;

    //Duyet qua tung Node trong danh sach va cong don kich thuoc file
    while(current != nullptr){
        totalSize += current->fileSize;
        current = current->next;
    }
    return totalSize;
}

//Ham loai bo cac file co kich thuoc nho nhat cho den khi tong size khong vuot qua maxSize
void loaiBoFileMin(Node *&head, int maxSize){
    //Duyet qua cac node xem co rong khong va tong size cua node co lon hon max size khong
    while(head != nullptr && tongSizeFile(head) > maxSize){

        //Tim file co kich thuoc nho nhat
        Node *prev = nullptr; //Node truoc do la rong
        Node *current = head; //Node hien tai la node dau tien 
        Node *smallest = head; //Node nho nhat danh dau cho node dau tien 
        Node *smallestPrev = nullptr; //Node nho nhat truoc do la rong

        while(current != nullptr){
            if(current->fileSize < smallest->fileSize){
                smallest = current;
                smallestPrev = prev;
            }

            prev = current;
            current = current->next;
        }

        //Xoa file nho nhat
        if(smallestPrev == nullptr){
            //Neu file nho nhat la node dau
            head = head->next;
        }else{
            smallestPrev->next = smallest->next;
        }
        delete smallest;
    }
}

//Ham in ra cac thong tin trong danh sach
void inFiles(Node *head){
    Node *current = head;
    while (current != nullptr){
        cout << "File: " << current->fileName << ", Size: " << current->fileSize 
        << " MB" << ", timeStamp: " << current->timeStamp << endl;
        current = current->next;
    }
}

int main(){
    Node *documentFolder = nullptr; //Thu muc ban dau rong
    int n;

    cout << "So file can them vao: " ;
    cin >> n;

    for(int i = 0; i < n; i++){
        string fileName;
        int fileSize, timeStamp;

        cout << "Nhap ten file: " ;
        cin >> fileName;
        cout << "Nhap kich thuoc file (MB): ";
        cin >> fileSize;
        cout << "Nhap thoi gian them vao (DD-MM-YY): ";
        cin >> timeStamp;

        insertFile(documentFolder, fileName, fileSize, timeStamp);
    }

    cout << "\nDanh sach file trong thu muc la: ";
    inFiles(documentFolder);

    int totalSize = tongSizeFile(documentFolder);
    cout << "\nTong kich thuoc file trong thu muc la: " << totalSize << " MB\n";

    loaiBoFileMin(documentFolder, MAXSIZE);

    cout << "\nDanh sach file sau khi loai bo de phu hop voi USB: \n";
    inFiles(documentFolder);

    cout << "\nTong kich thuoc file sau khi loai bo: " << tongSizeFile(documentFolder) << " MB\n";

    return 0;

}
#include<iostream>
#include<string>

using namespace std;

//Cau truc Node 
struct Node {
    string word;
    Node *next;
};

//Cau truc node tan suat 
struct FrequencyNode {
    string word;
    int count;
    FrequencyNode *next; 
};

//Tao mot Node moi 
Node *taoNode(const string &word){
    Node *newNode = new Node();
    newNode->word = word;
    newNode->next = nullptr;
    return newNode;
}

//Tao mot node tan suat moi
FrequencyNode *taoNodeTanSuat(const string &word){
    FrequencyNode *newNode = new FrequencyNode();
    newNode->word = word;
    newNode->count = 1;
    newNode->next = nullptr;
    return newNode;
}

//Them mot tu vao danh sach 
void themTuVaoDanhSach(Node *&head, const string &word){
    Node *newNode = taoNode(word);
    newNode->next = head;
    head = newNode;
}

//Tim hoac them tu vao danh sach tan suat
void timHoacThemVaoTanSuat(FrequencyNode *&head, const string &word){
    FrequencyNode *current = head;
    FrequencyNode *prev = nullptr;
    while(current != nullptr){
        if(current->word == word){
            current->count++;
            return;
        }
        prev = current;
        current = current->next;
    }
    FrequencyNode *newNode = taoNodeTanSuat(word);
    if(prev == nullptr){
        head = newNode;
    }else{
        prev->next = newNode;
    }
}

//Tim tu xuat hien nhieu nhat
string timTuXuatHienMax(Node *head){
    FrequencyNode *NodeTanSuat = nullptr;
    Node *current = head;
    while(current != nullptr){
        timHoacThemVaoTanSuat(NodeTanSuat, current->word);
        current = current->next;
    }

    string tuXuatHienMax;
    int tanSuatMax = 0;
    FrequencyNode *tanSuatHt = NodeTanSuat;
    while(tanSuatHt != nullptr){
        if(tanSuatHt->count > tanSuatMax){
            tuXuatHienMax = tanSuatHt->count;
            tuXuatHienMax = tanSuatHt->word;
        }
        tanSuatHt = tanSuatHt->next; 
    }

    //Giai phong bo nho cua danh sach tan suat
    while(NodeTanSuat != nullptr){
        FrequencyNode *temp = NodeTanSuat;
        NodeTanSuat = NodeTanSuat->next;
        delete temp;
    }
    return tuXuatHienMax;
}

//Loai bo tu lay
void loaiBoTuLay(Node *head){
    Node *current = head;
    while(current != nullptr && current->next != nullptr){
        if(current->word == current->next->word){
            Node *tuThua = head; 
            current->next = tuThua->next; 
            delete tuThua;
        }else{
            current = current->next;
        }
    }
}

//Dem so tu vung
int demSoTuVung(Node *head){
    FrequencyNode *NodeTanSuat = nullptr;
    Node *current = head;
    while(current != nullptr){
        timHoacThemVaoTanSuat(NodeTanSuat, current->word);
        current = current->next;
    }

    int count = 0;
    FrequencyNode *NodeTanSuatHt = NodeTanSuat;
    while(NodeTanSuatHt != nullptr){
        count++;
        NodeTanSuatHt = NodeTanSuatHt->next;
    }

    //Giai phong bo nho cua danh sach tan suat
    while(NodeTanSuat != nullptr){
        FrequencyNode *temp = NodeTanSuat;
        NodeTanSuat = NodeTanSuat->next;
        delete temp;
    }

    return count;
}

//In danh sach tu
void InTu(Node *head){
    Node *current = head;
    while(current != nullptr){
        cout << current->word << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    Node *Cau = nullptr;

    //Them tu vao danh sach 
    themTuVaoDanhSach(Cau, "xanh");
    themTuVaoDanhSach(Cau, "xanh");
    themTuVaoDanhSach(Cau, "dep");
    themTuVaoDanhSach(Cau, "troi");
    themTuVaoDanhSach(Cau, "xanh");

    cout << "Cau goc la: ";
    InTu(Cau);

    //Tu xuat hien nhieu nhat
    string tuXuatHienNhieuNhat = timTuXuatHienMax(Cau);
    cout << "\nTu xuat hien nhieu nhat la: " <<tuXuatHienNhieuNhat << endl;

    //Loai bo tu lay
    loaiBoTuLay(Cau);
    cout << "Cau sau khi loai bo tu lay la: " << endl;
    InTu(Cau);

    //Dem so tu vung
    int demSoTu = demSoTuVung(Cau);
    cout << "So tu vung la: " << demSoTu << endl;

    return 0; 
}


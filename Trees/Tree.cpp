#include <iostream>
#include <string>

using namespace std;

//Dinh nghia cau truc Node trong cay bieu thuc
struct Node{
    string value; //Gia tri cua Node (toan tu/toan hang)
    Node *left;  //Con tro cho nhanh ben trai
    Node *right; //Con tro cho nhanh ben phai
};

//Khoi tao cac gia tri cua Node
Node *khoiTaoNode(string value){
    Node *newNode  = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//Ham duyet cay theo Preorder (Duyet truoc) (Root -> Left -> Right)
void preOrder(Node *root){
    if(root){
        cout << root->value << " " ; //Goc
        preOrder(root->left); //De quy de duyet con ben trai
        preOrder(root->right); //De quy de duyet con ben phai
    }
}

//Ham duyet cay theo Inorder (Duyet giua) (Left -> Root -> Right)
void inOrder(Node *root){
    if(root){
        inOrder(root->left);
        cout << root->value << " " ;
        inOrder(root->right);
    }        
}

//Ham duyet cay theo Postorder (Duyet sau) (Right -> Right -> Root)
void postOrder(Node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

//Ham xay dung cay bieu thuc cho bieu thuc: a + 5 * b /c - c^8 + d * e^(1/2)
Node *xayDungCayBieuThuc(){
    //Tao cac Node la (Toan hang)
    Node *a = khoiTaoNode("a");
    Node *five = khoiTaoNode("5");
    Node *b = khoiTaoNode("b");
    Node *c = khoiTaoNode("c");
    Node * eight = khoiTaoNode("8");
    Node * d = khoiTaoNode("d");
    Node *e = khoiTaoNode("e");
    Node * half = khoiTaoNode("1/2");

    //Tao cac Node trung gian (Toan tu)
    Node *mult1 = khoiTaoNode("*"); //(5*b)
    mult1->left = five;
    mult1->right = b;

    Node *div = khoiTaoNode("/"); //(5*b)/c
    div->left = mult1;
    div->right = c;

    Node *add1 = khoiTaoNode("+"); //a + (5*b)/c
    add1->left = a;
    add1->right = div;

    Node *pow1 = khoiTaoNode("^"); //c^8
    pow1->left = c;
    pow1->right = eight;

    Node *sub = khoiTaoNode("-"); // a + ((5*b)/c) - (c^8)
    sub->left = add1;
    sub->right = pow1;

    Node *pow2 = khoiTaoNode("^"); // e^(1/2)
    pow2->left = e;
    pow2->right = half;

    Node *mult2 = khoiTaoNode("*"); //d * e^(1/2)
    mult2->left = d;
    mult2->right = pow2;

    Node *add2 = khoiTaoNode("+"); //((a + ((5 * b) / c)) - (c ^ 8)) + (d * (e ^ (1/2)))
    add2->left = sub;
    add2->right = mult2;

    //Tra ve goc cua cay
    return add2;
}

int main(){
    //Xay dung cay bieu thuc
    Node *root =xayDungCayBieuThuc();

    //In ra bieu thuc theo cac cach duyet
    cout << "Duyet truoc (Preorder): ";
    preOrder(root);
    cout << endl;

    cout << "Duyet giua (Inorder): ";
    inOrder(root);
    cout << endl;

    cout << "Duyet sau (Postorder): ";
    postOrder(root);
    cout << endl;

    return 0;
}
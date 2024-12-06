#include <iostream>
using namespace std;

void Sorting_func(int n, int arr[]){
	int low = 0, mid= 0, high = n - 1;
	//low chi toi cuoi mau Do
	//mid de duyet qua cac phan tu 
	//high chi toi dau phan mau xanh
	while(mid <= high){
		if(arr[mid] == 0){ //Neu la phan tu do
			if(low != mid){
				int temp = arr[low];
				arr[low] = arr[mid];
				arr[mid] = temp;
			}
			low ++;
			mid ++;
		}
		else if(arr[mid] == 1){ //Neu la ptu trang
			mid++;
		}
		else{ //Neu la phan tu xanh
			int temp = arr[mid];
			arr[mid] = arr[high];
			arr[high] = temp;
			high--;
		}
	}
}

void printArr(int n, int arr[]){
	for(int i = 0; i < n; i++){
		if(arr[i] == 0){
			cout << "red" << " " ;
		}
		else if(arr[i] == 1){
			cout << "white" << " ";
		}
		else{
			cout << "blue" << " ";
		}
	}
	cout << endl;
}

int main(){
	//Ma hoa mau thanh so: Do = 0; Trang = 1; Xanh = 2
	int arr[] = {2,0,2,0,0,1,0,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Mang ban dau: ";
	printArr(n, arr);
	Sorting_func(n, arr);
	cout << "Mang sau khi da sap xep: ";
	printArr(n, arr);
}


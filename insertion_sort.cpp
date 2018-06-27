#include<iostream>
using namespace std;

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int* arr, int n){
	int i, j;
	for(i = 1; i < n; i++){
		j = i;
		while(j > 0 && arr[j] < arr[j-1]){
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

void show(int* arr, int n){
	cout<<"Array: ";
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}

int main(){
	int n = 9;
	int arr[n] = {5,3,7,1,11,9,2,14,8};
	show(arr,n);
	insertion_sort(arr, n);
	show(arr,n);
	return 0;
}

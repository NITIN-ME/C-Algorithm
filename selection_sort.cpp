#include<iostream>
using namespace std;

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int* arr, int n){
	for(int i =0; i < n; i++){
		int min = i;
		for(int j = i; j < n; j++){
			if(arr[j] < arr[min]) min = j;
		}
		swap(&arr[i], &arr[min]);
	}
}

void show(int* arr, int n){
	for(int i = 0; i  <n; i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}

int main(){
	int n = 9;
	int arr[n] = {5,3,7,1,11,9,2,14,8};
	show(arr,n);
	selection_sort(arr, n);
	show(arr,n);
	return 0;
}

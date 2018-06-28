#include<iostream>
using namespace std;

int arr[1001] = {0};

void show(int i, int j){
	for(int k = i ; k <= j; k++){
		cout<<arr[k]<<"  ";
	}
	cout<<endl;
}

int show(int k){
	int num = 1;
	if(k == 0){
		return 0;
	}
	while(1){
		if(k == 1){
			break;
		}
		if(k % 2 == 1){
			k = 3 * k + 1;
		}
		else{
			k = k / 2;
		}
		num ++;
	}
	return num;
}


int max(int i, int j){
	int ma = i;
	for(int z = i; z <= j; z++){
		if(arr[ma]< arr[z]){
			ma = z;
		}
	}
	cout<<"returning..."<<endl;
	return arr[ma];
}


int main(){
	cout<<"Starting computation..."<<endl;
	for(int i = 0 ; i <= 1001; i++){
		arr[i] = show(i);
		cout<<"Num: "<<i<<endl;
	}
	while(1){
		cout<<"Enter the two numbers: ";
		int a, b;
		cin >> a >> b;
		cout<<"a: "<<a<<", b: "<<b<<endl;
		cout<<max(a, b)<<endl;
	}
	return 0;
}

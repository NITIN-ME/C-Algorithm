#include<iostream>
#include<vector>
using namespace std;

class Heap{
	private:
		int* arr;
		int size;
		int capacity;
	public:
		Heap(int n);
		int parent(int i);
		int left(int i);
		int right(int i);
		void heapify(int i);
		void show();
		void set(int k);
		int getsize();
		int getcapacity();
		void remove();
		void buildheap(int* k, int n);
		void swap(int* arr, int a, int b);
		int top();
		void pop();
		void topk(int k, vector<int>& v);
		void heapsort();
};

int Heap::top(){
	if(this->size > 0)
		return this->arr[0];
	else
		return -1;
}

void Heap::pop(){
	int z = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = z;
	size--;
	heapify(0);
}

void Heap::topk(int k, vector<int>& v){
	int n = k < size?k:size;
	for(int z = 0; z < n; z++){
		v.push_back(top());
		pop();
	}
}

void Heap::heapsort(){
	int r = size;
	for(int z = 0; z < r; z++){
		pop();
	}
	size = r;
}

Heap::Heap(int n){
	arr = new int[n];
	size = 0;
	capacity = n;
}

void Heap::remove(){
	if(size > 0){
		size--;
	}
}

int Heap::getsize(){
	return size;
}

int Heap::getcapacity(){
	return capacity;
}

void Heap::set(int k){
	if(size < capacity){
		arr[size] = k;
		size++;
	}
}

void Heap::show(){
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}

int Heap::parent(int i){
	int k = (i-1)/2;
	return k;
}

int Heap::left(int i){
	return (2 * i + 1);
}

int Heap::right(int i){
	return (2 * i + 2);
}

void Heap::heapify(int i){
	int n = size;
	int biggest = i;
	while(1){
		int l = left(i);
		int r = right(i);
		if(l < n && arr[l] > arr[i]){
			biggest = l;
		}
		if(r < n && arr[r] > arr[biggest]){
			biggest = r;
		}
		if(biggest != i){
			swap(arr, i, biggest);
			i = biggest;
		}
		else{
			return;
		}
	}
}

void Heap::swap(int* arr, int a, int b){
	int k = arr[a];
	arr[a] = arr[b];
	arr[b] = k;
}

void Heap::buildheap(int* k, int n){
	for(int i = 0; i < n; i++){
		cout<<"setting "<<i<<" to "<<k[i]<<endl;
		set(k[i]);
	}
	for(int k = (n-1)/2; k >= 0; k--){
		heapify(k);
	}
}

int main(){
	int k[] = {16,4,10,14,7,9,3,2,8,1};
	Heap h(10);
	cout<<"size: "<<h.getsize()<<", capacity: "<<h.getcapacity()<<endl;
	h.buildheap(k, 10);
	h.show();
	cout<<"size: "<<h.getsize()<<", capacity: "<<h.getcapacity()<<endl;
	cout<<endl<<endl<<"----------------------------------------------------------"<<endl;
	cout<<"max is: "<<h.top()<<endl;
	vector<int> v;
	/*
	h.topk(7,v);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<"  ";
	}
	*/
	
	cout<<"size: "<<h.getsize()<<", capacity: "<<h.getcapacity()<<endl;
	h.show();
	h.heapsort();
	h.show();
	cout<<"size: "<<h.getsize()<<", capacity: "<<h.getcapacity()<<endl;
	
	return 0;
}

#ifndef _FUNNY_
#define _FUNNY_


#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
};

class Stack{
	private:
		int size_;
		Node* head;
	public:
		Stack(){
			size_ = 0;
			head = nullptr;
		}
		
		bool empty(){
			return size_ == 0;
		}
		
		int size(){
			return size_;
		}
		
		int top(){
			return head->value;
		}
		
		void push(int num){
			Node* node = new Node();
			node->value = num;
			node->next = head;
			head = node;
			size_++;
		}
		
		void pop(){
			if(size_ == 0){
				cout<<"Stack is empty!"<<endl;
			}
			else{
				Node* haha = head;
				head = head->next;
				size_--;
				delete haha;
			}
		}
};

#endif

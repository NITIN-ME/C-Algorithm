#ifndef _FUNNY_
#define _FUNNY_

#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;
		Node* prev;
	Node(){
		value = 0;
		next = prev = nullptr;
	}
};

class Queue{
	private:
		int queuesize;
		Node* head;
		Node* tail;
	public:
		Queue(){
			queuesize = 0;
			head = new Node();
			tail = new Node();
		}
		
		bool empty(){
			return queuesize == 0;
		}
		
		int size(){
			return queuesize;
		}
		
		int front(){
			if(queuesize == 0){
				cout<<"Queue is empty!"<<endl;
				return -1;
			}
			else{
				return head->prev->value;
			}
		}
		
		int back(){
			if(queuesize == 0){
				cout<<"Queue is empty!"<<endl;
				return -1;
			}
			else{
				return tail->next->value;
			}
		}
		
		void push(int num){
			Node* node = new Node();
			node->value = num;
			if(queuesize == 0){
				node->next = head;
				head->prev = node;
				tail->next = node;
				node->prev = tail;
			}
			else{
				tail->next->prev = node;
				node->next = tail->next;
				node->prev = tail;
				tail->next = node;
			}
			queuesize++;
		}
		
		void pop(){
			if(queuesize == 0){
				cout<<"Queue is empty"<<endl;
			}
			else{
				Node* temp = head->prev->prev;
				delete head->prev;
				head->prev = temp;
				temp->next = head;
				queuesize--;
			}
		}
		
		void print(){
			Node* temp = tail->next;
			while(temp != head){
				cout<<temp->value<<"  ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		void printreverse(){
			Node* temp = head->prev;
			while(temp != tail){
				cout<<temp->value<<"  ";
				temp = temp->prev;
			}
			cout<<endl;
		}
};

#endif

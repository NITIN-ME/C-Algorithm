#include<iostream>
#include<string>
using namespace std;


int finder(string p, string q){
	int m = p.length();
	int n = q.length();
	for(int i = 0; i <= (m-n); i++){
		int z = 0;
		while(z < n && p[i+z] == q[z]){
			z += 1;
		}
		if(z == n) return i;
	}
	return -1;
}

int main(){
	string s = "aababba";
	string f = "abba";
	cout<<finder(s, f)<<endl;
	string a = "Nitin Gandhi";
	string find = "and";
	cout<<finder(a, find)<<endl;
	return 0;
}

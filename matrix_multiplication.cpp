#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<int> vect;

void showvec(vector<int> &v){
	for(int i =0 ; i < v.size(); i++){
		cout<<v[i]<<"  ";
	}
	cout<<endl;
}

void showmat(matrix& m){
	for(int i = 0; i < m.size(); i++){
		showvec(m[i]);
	}
}

int main(){
	cout<<"Select the first matrix size:"<<endl;
	int m1, n1;
	cin >>m1>>n1;
	matrix mat1(m1);
	int k;
	cout<<"m1: "<<m1<<", n1: "<<n1<<endl;
	for(int i = 0; i < m1; i++){
		mat1[i].resize(n1);
		for(int j =0 ; j < n1 ; j ++){
			cin>>k;
			mat1[i][j] = k;
		}
	}
	showmat(mat1);
	cout<<"Select the second matrix size:"<<endl;
	int m2, n2;
	cin >>m2>>n2;
	matrix mat2(m2);
	cout<<"m2: "<<m2<<", n2: "<<n2<<endl;
	for(int i = 0; i < m2; i++){
		mat2[i].resize(n2);
		for(int j =0 ; j < n2 ; j ++){
			cin>>k;
			mat2[i][j] = k;
		}
	}
	showmat(mat2);
	
	matrix result(m1);
	if(n1 != m2) cout<<"MATRIX MULTIPLICATION NOT POSSIBLE"<<endl;
	else{
		/*
			m1 * n2
		*/
		for(int i = 0; i < m1; i++){
			for(int j = 0; j < n2; j++){
				result[i].resize(n2);
				result[i][j] = 0;
				for(int k = 0; k < n1; k++){
					result[i][j] += mat1[i][k] * mat2[k][j];	
				}
			}
		}
	cout<<endl<<"---------------------------------------------"<<endl;
	showmat(result);
	}
	return 0;
}

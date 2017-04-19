#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n = 100;
	vector< vector<double> a(n)> mat_A(n);
	vector< vector<double> > mat_B;
	vector< vector<double> > mat_C;
	cout << "safe";
	mat_A.resize(n);
	/*
	for(int i=0; i<n; ++i){
		mat_A[i].resize(n);
	}
	*/
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++i){
			mat_A[i][j] = i*10 + j;
		}	
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << mat_A[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

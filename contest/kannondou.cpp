#include <algorithm>
#include <iostream>
using namespace std;
int A[128], N;

int main()
{
	int n=5;
	A[0] = 1;
	for(int i=1; i<=n; ++i){
		A[i] = A[i-1];
		if(i>=2) A[i] += A[i-2];
		if(i>2)  A[i] += A[i-3];
		cout << "i=" << i << "\n" << A[i] << endl; 
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, n;
	cin >> T;
	cin >> n;
	vector<int> P(n, -1);

	int c, p;
	// edgeの数はノード数-1だから，edgeの読み込み回数はn-1
	for(int i=0; i<n-1; ++i){
		cin >> p >> c;
		c--;
		p--;
		P[c] = p;
	}
	for(int i=0; i<n; ++i){
		//cout << P[i] << " ";
	}
	
	int a, b;
	// 入力された値を-1することを忘れていた．
	cin >> a >> b;
	a--;
	b--;
	int x = a;
	while(1){
		cout << x+1 << "-->" << P[x]+1 << "\n";
		if(P[x]==-1) break;
		x = P[x];
	}
	cout << "\n";
	return 0;
}

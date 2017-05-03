#include <iostream>
#include <map>
using namespace std;

// mp[a] は，頂点aの字数を表す
int main()
{
	int a, b;
	while(1){
		map<int, int> mp;
		mp.clear();
		while(1){
			if(!(cin >> a >> b)) return 0;
			//cin >> a;
			//cin >> b;

			if(mp[a]==0) mp[a] =1;
			//else(mp[a]); mp[a] +=1;  elseのあとifつけ忘れ．{}で囲まないスタイルに慣れていなかったから
			else if (mp[a]) mp[a] +=1;

			if(mp[b]==0) mp[b] =1;
			else if (mp[b]) mp[b] +=1;
			//cout << "degree of a: " << mp[a] << "\ndegree of b:" << mp[b] << "\n";
			// End condition
			if(a==0) break;

		}

		//int hantei1 = mp[1]%2;
		//int hantei2 = mp[2]%2;
		bool hantei3 = true;
		int f=1;
		if(!(mp[1]%2 == 1 && mp[2]%2 == 1)) f=0;
		//それ以外のVerteies
		for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
			if(it->first != 1 && it->first !=2){
				if(it->second %2 == 1){
					hantei3 = false;
					break;
				}
			}
		}
		
		if(f && hantei3==true){
			cout << "OK\n";
		}
		else {
			cout << "NG\n";
		}
	}

//	for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
//		cout << "degrees of " << it->first << ": " << it->second << '\n';
//	}
	
	return 0;
}

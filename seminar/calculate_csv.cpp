#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdlib.h> // atoi

using namespace std;

void load_csv( string filename, vector< vector<double> >& vv );
void print_vv( vector< vector<double> >& vv );

int main(int argc, char*argv[])
{
	string filename = argv[1];
	int n = atoi(argv[2]);
	ifstream ifs(filename);
	if(!ifs){
		cout << "Input error";
		return 1;
	}

	vector< vector<double> > v;
	load_csv(filename, v);
	double whole_time=0.0;
	double cnt=0;

	/*
	for(auto it = v.begin(); it!=v.end(); ++it){
		whole_time += it->[1]; // add the column of time.
		cnt++;
	}
	*/
	for(int i=0; i<v.size(); ++i){
		whole_time += v[i][1]; // add the column of time.
		cnt++;
	}
	double num_cluc = 2.0 * pow(n, 3);
	double t_ave = whole_time / cnt;
	//double gflops = num_cluc * cnt / ( pow(10.0, 9) *  whole_time);
	double gflops = num_cluc / ( pow(10.0, 9) *  t_ave);
	//printf("%d,%f,%f\n", n, whole_time/count, gflops);
	cout << n << ',' << t_ave << ',' << gflops << '\n';

	return 0;
}

void load_csv( string filename, vector< vector<double> >& vv )
{
  ifstream ifs( filename );
  string str;
  vector<double> one_row;

  while( getline( ifs, str) ){
    one_row.clear();
    string token;
    istringstream stream( str );

    // 1行のうち，文字列とコンマを分割する
    while( getline( stream, token, ',' ) ){
      one_row.push_back( stod( token ) );
    }
    vv.push_back( one_row );
  }
}

void print_vv( vector< vector<double> >& vv )
{
  for( auto p = vv.begin(); p != vv.end(); ++p ){
    for( auto q = p->begin(); q != p->end(); ++q ){
      cout << *q << " ";
    }
    cout << endl;
  }
}



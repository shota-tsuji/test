#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#define HEIGHT 5
#define WIDTH 3
using namespace std;

void load_csv( string filename, vector< vector<double> >& vv );

int main()
{
  //vector< vector<double> > array2D;
  vector< vector<double> > A;
  string filename = "./data3.txt";

  /*
  // Set up sizes. (HEIGHT x WIDTH)
  array2D.resize( HEIGHT );
  for( int i = 0; i < HEIGHT; ++i ){
    array2D[i].resize( WIDTH );
  }
  */

    // Put some values in
    //array2D[1][2] = 6.0;
    //array2D[3][1] = 5.5;

    // 転地して，各行ごと（データごと）で平均をとりたい
    //for()

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

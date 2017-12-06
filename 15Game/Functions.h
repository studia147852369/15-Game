#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <iostream>

 typedef uint64_t U64;
using namespace std;

using namespace std;
vector< vector<int> > doReverseMoves(char move, vector< vector<int> > puzzle);
void print( vector< vector<int> >  const &puzzle);
U64 fact(int n);
int lessThan(vector< vector<int> > const &puzzle, int i, int j);
vector< vector<int> > toPuzzle(U64 number,const int &xSizePuzzle, const int &ySizePuzzle );
U64 toNumber(vector< vector<int> > const &puzzle);
vector<char> canMove(vector< vector<int> > const &puzzle,const int &xSizePuzzle, const int &ySizePuzzle );
vector< vector<int> > doMoves(char move, vector< vector<int> > puzzle);
bool checkCOuldBeResolve(vector< vector<int> >const &puzzle);


#endif // FUNCTIONS_H_INCLUDED

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

vector<char>  dfs(vector< vector<int> > &puzzle, const int &xsizePuzzle,const int &ySizePuzzle );
vector<char> dfsHeuristic1(vector< vector<int> > &puzzle, const int &xsizePuzzle,const int &ySizePuzzle );
vector<char> dfsHeuristic2(vector< vector<int> > &puzzle, const int &xsizePuzzle,const int &ySizePuzzle );

U64 fact(int n);
U64 toNumber(vector< vector<int> > const &puzzle);
void print( vector< vector<int> >  const &puzzle);
int lessThan(vector< vector<int> > const &puzzle, int i, int j);
bool checkCOuldBeResolve(vector< vector<int> >const &puzzle);

vector< vector<int> > doReverseMoves(char move, vector< vector<int> > puzzle);
vector< vector<int> > doMoves(char move, vector< vector<int> > puzzle);
vector< vector<int> > toPuzzle(U64 number,const int &xSizePuzzle, const int &ySizePuzzle );
vector<char> canMove(vector< vector<int> > const &puzzle,const int &xSizePuzzle, const int &ySizePuzzle );

vector<char> heuristicMove(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard);
vector<char> heuristic2Move(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard);

vector< vector<int> > Heuristic1(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard);
vector< vector<int> > Heuristic2(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard);


#endif // FUNCTIONS_H_INCLUDED

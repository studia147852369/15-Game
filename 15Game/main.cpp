#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include "Functions.h"

using namespace std;


    set<U64> uniqValues;
   vector<char> pathtable;
 vector< vector<int> > puzzle1;

  vector< vector<int> > dfs(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
    {
        for (auto  z:canMove(puzzle, xSizeBoard, ySizeBoard))
        {
            puzzle = doMoves(z,puzzle);
            U64 value = toNumber(puzzle);
            if ( value != 0 )
            {
                if(!uniqValues.count(value))
                {
                    print(puzzle);
                    uniqValues.insert(value);
                    pathtable.push_back(z);
                    puzzle1 = dfs(puzzle, xSizeBoard, ySizeBoard);
                    if (toNumber(puzzle1) == 0)
                        return puzzle1;
                    else
                        puzzle = doReverseMoves(z, puzzle);
                }
                else
                    puzzle = doReverseMoves(z, puzzle);
            }
            else
                pathtable.push_back(z);
        }
     return puzzle;
    }


vector< vector<int> > heuristic1(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
    {
        vector<char> move = heuristicMove(puzzle,xSizeBoard,ySizeBoard );
        for (auto  z:move)
        {
            puzzle = doMoves(z,puzzle);
            U64 value = toNumber(puzzle);
            if ( value != 0 )
            {
                if(!uniqValues.count(value))
                {
                    print(puzzle);
                    uniqValues.insert(value);
                    pathtable.push_back(z);
                    puzzle1 = heuristic1(puzzle, xSizeBoard, ySizeBoard);
                    if (toNumber(puzzle1) == 0)
                        return puzzle1;
                    else
                        puzzle = doReverseMoves(z, puzzle);
                }
                else
                    puzzle = doReverseMoves(z, puzzle);
            }
            else
                {pathtable.push_back(z);
                break;}
        }
     return puzzle;
    }







int main() {

    const int xsizePuzzle  = 3;
    const int ySizePuzzle =3;
    vector< vector<int> > puzzle;
    puzzle.resize(3);


    puzzle[0].push_back(1);
    puzzle[0].push_back(9);
    puzzle[0].push_back(3);

    puzzle[1].push_back(5);
    puzzle[1].push_back(2);
    puzzle[1].push_back(6);

     puzzle[2].push_back(4);
    puzzle[2].push_back(7);
    puzzle[2].push_back(8);

  /*
    const int xsizePuzzle  = 4;
    const int ySizePuzzle = 4;
    vector< vector<int> > puzzle;
    puzzle.resize(4);

    puzzle[0].push_back(16);
    puzzle[0].push_back(2);
    puzzle[0].push_back(3);
    puzzle[0].push_back(4);

    puzzle[1].push_back(1);
    puzzle[1].push_back(5);
    puzzle[1].push_back(7);
    puzzle[1].push_back(8);

    puzzle[2].push_back(9);
    puzzle[2].push_back(6);
    puzzle[2].push_back(11);
    puzzle[2].push_back(12);

    puzzle[3].push_back(13);
    puzzle[3].push_back(10);
    puzzle[3].push_back(14);
    puzzle[3].push_back(15);
*/

if(checkCOuldBeResolve(puzzle))
{
    //poczatek
       print(puzzle) ;
       cout << "++++++++++++++++++++\n\n";
       uniqValues.insert(toNumber(puzzle));
       vector< vector<int> > wynikKoncowy =  heuristic1(puzzle, xsizePuzzle, ySizePuzzle);
 cout << "\n\n\n\n";
    //koniec
    cout << "\n KONIEC n\"";
    cout << "Wynik \n";
    print(wynikKoncowy);
    for (auto x:pathtable)
        cout << x << " " ;
    cout << endl;
}


 return 0;
}

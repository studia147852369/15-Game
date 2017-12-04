#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include "Functions.h"

using namespace std;

struct element{
int elementVvalue;
int parentValue;
};
    set<U64> uniqValues;
   vector<char> pathtable;

    vector<char> dfs(vector< vector<int> > &puzzle, const int &xSizeBoard, const int &ySizeBoard)
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++\n++++++++++++++++++++++++++++++++++++++++\n\n";
        for (auto  z:canMove(puzzle, xSizeBoard, ySizeBoard))
            { cout << "Zrobiono ruch: " << z  <<"\nMozliwe ruchy: ";
                for (auto  zz:canMove(puzzle, xSizeBoard, ySizeBoard))
                    cout << zz << " ";cout << endl;

                puzzle = doMoves(z,puzzle);

                U64 value = toNumber(puzzle);cout<< "VALUE " <<value << endl;
                uniqValues.insert(value);
                uniqValues.insert(1);
uniqValues.insert(700);

              if ( value != 0 )
                {        print(puzzle);
             cout << "Wartosci ";   for (auto x: uniqValues)
                    cout << x << " ";cout << endl;

                        if(*uniqValues.begin() == value)
                            {
                                dfs(puzzle, xSizeBoard, ySizeBoard);
                            }
                        else{
                            puzzle = doReverseMoves(z, puzzle);
                            break;
                        }
                }
     //           cout << "Wstawiamy znak : " << z << endl;
                else{
                    pathtable.push_back(z);
                    break;
                }
            }
        return pathtable;
    }


int main() {
    const int xsizePuzzle  = 3;
    const int ySizePuzzle = 3;
    vector< vector<int> > puzzle;
    puzzle.resize(3);

    puzzle[0].push_back(1);
    puzzle[0].push_back(2);
    puzzle[0].push_back(3);

    puzzle[1].push_back(9);
    puzzle[1].push_back(4);
    puzzle[1].push_back(5);
    puzzle[2].push_back(7);
    puzzle[2].push_back(8);
    puzzle[2].push_back(6);
   /* puzzle[1].push_back(11);
    puzzle[1].push_back(16);

    puzzle[2].push_back(15);
    puzzle[2].push_back(2);
    puzzle[2].push_back(12);
    puzzle[2].push_back(5);

    puzzle[3].push_back(14);
    puzzle[3].push_back(3);
    puzzle[3].push_back(1);
    puzzle[3].push_back(4);
*/

if(checkCOuldBeResolve(puzzle))
{
    //poczatek
        print(puzzle) ;
        uniqValues.insert(toNumber(puzzle));
        vector<char> resultTable = dfs(puzzle, xsizePuzzle, ySizePuzzle);

    //koniec
    cout << "\n\n\n\n\n KONIEC \n\n\"";
        print(puzzle);
        for (auto x:resultTable)
            cout << x << " " ;
}


 return 0;
}

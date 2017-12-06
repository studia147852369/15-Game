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
int licz ;
  void dfs(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
    {cout << "++++++++++++++++++++++++++++++++++++++++++++ \n";
            for (auto  z:canMove(puzzle, xSizeBoard, ySizeBoard)){
                puzzle = doMoves(z,puzzle);
                U64 value = toNumber(puzzle);
                cout << "RUCh W " << z <<endl;
              if ( value != 0 )
                {                                print(puzzle);

                        if(!uniqValues.count(value))
                            {
                                uniqValues.insert(value);
                                pathtable.push_back(z);
                                dfs(puzzle, xSizeBoard, ySizeBoard);
                                cout << "stan po wyjsciu z petli " << endl;
                                print(puzzle);

                            }
                        else
                            {
                                puzzle = doReverseMoves(z, puzzle);
                                cout << "ruch wstecz z";
                            }
                }

                else
                    {
                        pathtable.push_back(z);
                        print(puzzle);
                        cin >> licz;break;
                    }
            }
    }


int main() {
   /* const int xsizePuzzle  = 2;
    const int ySizePuzzle = 2;
    vector< vector<int> > puzzle;
    puzzle.resize(2);

    puzzle[0].push_back(1);
    puzzle[0].push_back(4);
    puzzle[1].push_back(3);

    puzzle[1].push_back(2);
   */
    const int xsizePuzzle  = 3;
    const int ySizePuzzle = 3;
    vector< vector<int> > puzzle;
    puzzle.resize(3);

    puzzle[0].push_back(1);
    puzzle[0].push_back(2);
    puzzle[0].push_back(3);

    puzzle[1].push_back(4);
    puzzle[1].push_back(5);
    puzzle[1].push_back(9);
    puzzle[2].push_back(7);
    puzzle[2].push_back(8);
    puzzle[2].push_back(6);

    /*puzzle[1].push_back(5);
    puzzle[1].push_back(9);
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
      // uniqValues.insert(toNumber(puzzle));
        dfs(puzzle, xsizePuzzle, ySizePuzzle);

    //koniec
    cout << "\n\n\n\n\n KONIEC \n\n\"";

    }


 return 0;
}

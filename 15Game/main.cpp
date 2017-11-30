#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include "Functions.h"

using namespace std;

int main() {
    const int xsizePuzzle  = 4;
    const int ySizePuzzle = 4;
    vector< vector<int> > puzzle;
    puzzle.resize(4);

    puzzle[0].push_back(16);
    puzzle[0].push_back(7);
    puzzle[0].push_back(15);
    puzzle[0].push_back(9);

    puzzle[1].push_back(8);
    puzzle[1].push_back(13);
    puzzle[1].push_back(11);
    puzzle[1].push_back(3);

    puzzle[2].push_back(6);
    puzzle[2].push_back(2);
    puzzle[2].push_back(5);
    puzzle[2].push_back(14);

    puzzle[3].push_back(12);
    puzzle[3].push_back(4);
    puzzle[3].push_back(10);
    puzzle[3].push_back(1);

    U64 num = toNumber(puzzle);
    print(puzzle);
    cout << "\n\nZe stanu na ukladanke :\n\n";
    print((toPuzzle(num, xsizePuzzle,ySizePuzzle)));;

    vector<char> xx = canMove(puzzle,xsizePuzzle,ySizePuzzle);
    cout << "\n\n\n\n\n";
    puzzle = doMoves('G',puzzle);
    print(puzzle);
    xx = canMove(puzzle,xsizePuzzle,ySizePuzzle);


    return 0;
}

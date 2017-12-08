#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include "Functions.h"

using namespace std;
int main() {
/*
    const int xsizePuzzle  = 3;
    const int ySizePuzzle =3;
    vector< vector<int> > puzzle;
    puzzle.resize(3);


    puzzle[0].push_back(1);
    puzzle[0].push_back(2);
    puzzle[0].push_back(3);

    puzzle[1].push_back(4);
    puzzle[1].push_back(9);
    puzzle[1].push_back(6);

     puzzle[2].push_back(7);
    puzzle[2].push_back(5);
    puzzle[2].push_back(8);

  */
    const int xsizePuzzle  = 4;
    const int ySizePuzzle = 4;
    vector< vector<int> > puzzle;
    puzzle.resize(4);

    puzzle[0].push_back(1);
    puzzle[0].push_back(2);
    puzzle[0].push_back(3);
    puzzle[0].push_back(4);

    puzzle[1].push_back(5);
    puzzle[1].push_back(6);
    puzzle[1].push_back(7);
    puzzle[1].push_back(8);

    puzzle[2].push_back(9);
    puzzle[2].push_back(10);
    puzzle[2].push_back(11);
    puzzle[2].push_back(12);

    puzzle[3].push_back(13);
    puzzle[3].push_back(16);
    puzzle[3].push_back(14);
    puzzle[3].push_back(15);



//uzywamy "dfs(puzzle,xsizePuzzle, ySizePuzzle); " zwykły dfs
//  "dfsHeuristic1(puzzle,xsizePuzzle, ySizePuzzle)" heurystykanr1
//  "dfsHeuristic2(puzzle,xsizePuzzle, ySizePuzzle)" heurystykanr2

// Jezeli bedziesz tu chail robic switcha to wyczyscic musisz vektory pathtable uniqid idt !!!!!!
dfs(puzzle,xsizePuzzle, ySizePuzzle);
//dfsHeuristic1(puzzle,xsizePuzzle, ySizePuzzle);

//cout << "MAIN " <<endl;
//print(puzzle);


//zadzwon do mnie to powiem ci Ci

 return 0;
}

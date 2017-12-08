#include "Functions.h"
#include <vector>
#include<list>
#include<algorithm>
#include <fstream>


    set<U64> uniqValues;
    vector<char> pathtable;
    vector< vector<int> > puzzle1;

void savetoFile(string name){
  ofstream myfile;
  myfile.open (name);

  for (auto x:pathtable)
    myfile << x;

  myfile.close();
}

void print( vector< vector<int> >  const &puzzle){
    cout << "___________________________\n" <<endl;
    for (int x=0; x<puzzle.size(); x++)
    {
        cout << "||";
        for (int y=0; y<puzzle[x].size(); y++)
            {
                if(puzzle[x][y] == puzzle.size()*puzzle[puzzle.size()-1].size() )
                    cout <<setw(6) << "  |";
                else
                    cout <<setw(3) << puzzle[x][y] << "  |";
            }
        cout << "|" << endl;
        cout << "___________________________\n" <<endl;
    }
}

//silnia
U64 fact(int n) {
    U64 res = 1;
    for(int i=2; i<=n; ++i)
        res *= i;
    return res;
}
//funkcja licząca ile jest mniejszych elementów w układance od danej pozycji
int lessThan(vector< vector<int> > const &puzzle, int i, int j) {
    int counter = 0;
    int k, l;
    for(k = i; k < puzzle.size(); k++) {
        if (k > i) l = 0; else l=j;
        for(l ; l < puzzle.size(); l++) {
            if (puzzle[k][l] < puzzle[i][j]) {
                counter++;
        }
        }
    }
    return counter;
}
vector< vector<int> > toPuzzle(U64 number,const int &xSizePuzzle, const int &ySizePuzzle )
{   int size = xSizePuzzle * ySizePuzzle;
    vector<int> temporary;;
    for (int i=0; i<size;  i++)
        temporary.push_back(i+1);;

    vector< vector<int> > puzzle;
    puzzle.resize(ySizePuzzle);
    int index ;
    for (int i=0; i<ySizePuzzle; i++)
    {
        for (int z=0; z<xSizePuzzle; z++)
        {
            U64 factresult = fact(ySizePuzzle*xSizePuzzle-(ySizePuzzle*i+z +1));
            U64 restFromDivided = number % factresult;
            index = number / factresult;

            puzzle[i].push_back(temporary[index]);
            temporary.erase(temporary.begin() + index);
            number =restFromDivided;
        }
    }
        return puzzle;
}

U64 toNumber(vector< vector<int> > const &puzzle) {
    U64 number = 0;
    int size = puzzle.size();
    int numOfEl = size * size - 1;

    for(int i = 0; i < size; i++)
    {
        for(int j=0; j < size; j++)
        {
            number += (lessThan(puzzle, i, j))*fact(numOfEl--);
        }
    }
    return number;
}

vector<char> canMove(vector< vector<int> > const &puzzle,const int &xSizePuzzle, const int &ySizePuzzle ) {
    vector<char> moves;
    int puzzleSize = puzzle.size()*puzzle.size();
    for (int i=0; i<ySizePuzzle; i++)
      {

        for (int z=0; z<xSizePuzzle; z++)
        {
            if (puzzle[i][z] == puzzleSize)
            {
                if ( i>0 )
                    moves.push_back('G');
                if( i<ySizePuzzle -1)
                    moves.push_back('D');
                if ( z<xSizePuzzle && z>0 )
                    moves.push_back('L');
                if ( z>=0 && z<xSizePuzzle-1)
                    moves.push_back('P');
            }
        }
      }
    return moves;
}

vector< vector<int> > doMoves(char move, vector< vector<int> > puzzle)
{
int temp;
for (int i=0; i<puzzle.size(); i++)
{
    for (int z=0; z<puzzle[i].size(); z++)
    {
       if (puzzle[i][z] == puzzle.size()*puzzle.size())
        {
          if( move == 'G')
            {
                temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i-1][z];
                puzzle[i-1][z] = temp;
                return puzzle;
            }

          if ( move == 'L' )

            {
                temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i][z-1];
                puzzle[i][z-1] = temp;
                return puzzle;
            }

          if ( move == 'P' )
            {   temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i][z+1];
                puzzle[i][z+1] = temp;
                return puzzle;

            }
        if ( move == 'D' )
            {   temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i+1][z];
                puzzle[i+1][z] = temp;
                return puzzle;
            }
        }
    }
}
    return puzzle;

}
vector< vector<int> > doReverseMoves(char move, vector< vector<int> > puzzle)
{
int temp;
for (int i=0; i<puzzle.size(); i++)
    {
        for (int z=0; z<puzzle[i].size(); z++)
        {
            if (puzzle[i][z] == puzzle.size()*puzzle.size())
            {

            if( move == 'G')
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i+1][z];
                    puzzle[i+1][z] = temp;
                    return puzzle;

                }
            if ( move == 'D' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i-1][z];
                    puzzle[i-1][z] = temp;
                    return puzzle;

                }
            if ( move == 'L' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i][z+1];
                    puzzle[i][z+1] = temp;
                    return puzzle;

                }
            if ( move == 'P' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i][z-1];
                    puzzle[i][z-1] = temp;
                    return puzzle;

                }
            }
        }

    }
    return puzzle;
}

bool checkCOuldBeResolve(vector< vector<int> > const &puzzle){
    int inv_count = 0;
    int numberBlank;
    vector<int> tempTabele;
    for (int x=0; x<puzzle.size(); x++)
        for (int y=0; y<puzzle[x].size(); y++)
        {
            if(puzzle[x][y] == puzzle.size()*puzzle.size() )
                numberBlank = puzzle.size()-x ;
            tempTabele.push_back(puzzle[x][y]);
        }

    for (int i = 0; i < tempTabele.size(); i++)
    {
        for (int j = i + 1; j <tempTabele.size(); j++)
        {
            if (tempTabele[j] && tempTabele[i] && tempTabele[i] > tempTabele[j] && tempTabele[i] != tempTabele.size())
                inv_count++;
        }
    }

    if (puzzle.size() & 1)
        return !(inv_count & 1);

    else
    {
        if (numberBlank & 1)
            return !(inv_count & 1);
        else
            return inv_count & 1;
    }
}


 vector<char> heuristicMove(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
 {


     vector<char> move =canMove(puzzle, xSizeBoard, ySizeBoard);
     vector<int> uniqId;
     vector<char> result;
     int index = 0;
     for (auto x:move)
        uniqId.push_back(toNumber(doMoves(x,puzzle)));
do{

    for (int i=0; i<uniqId.size(); i++){
        if(uniqId[i] < uniqId[index])
            index = i;
    }
    result.push_back(move[index]);
    uniqId.erase(uniqId.begin()+index);
    move.erase(move.begin()+ index);
    index = 0;
   }
    while(uniqId.size()!= 0);
return result ;
}

//*******************************************

void dfsHeuristic1(vector< vector<int> > &puzzle, const int &xsizePuzzle,const int &ySizePuzzle ){
if(checkCOuldBeResolve(puzzle))
    {
       print(puzzle) ;
       uniqValues.insert(toNumber(puzzle));
       puzzle =  Heuristic1(puzzle, xsizePuzzle, ySizePuzzle);

        print(puzzle);
        savetoFile("dfsHeuristic1");
    }
else
    cout << "Brak rozwiazania" << endl;

}
//*******************************************

vector< vector<int> > Heuristic1(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
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
                    //print(puzzle);
                    uniqValues.insert(value);
                    pathtable.push_back(z);
                    puzzle1 = Heuristic1(puzzle, xSizeBoard, ySizeBoard);
                    if (toNumber(puzzle1) == 0)
                        return puzzle1;
                    else
                        puzzle = doReverseMoves(z, puzzle);
                }
                else
                    puzzle = doReverseMoves(z, puzzle);
            }
            else
                {
                    pathtable.push_back(z);
                    break;
                }
        }
     return puzzle;
    }
//*******************************************

 vector< vector<int> > dfsSimply(vector< vector<int> > puzzle, const int &xSizeBoard, const int &ySizeBoard)
    {
        for (auto  z:canMove(puzzle, xSizeBoard, ySizeBoard))
        {
            puzzle = doMoves(z,puzzle);
            U64 value = toNumber(puzzle);
            if ( value != 0 )
            {
                if(!uniqValues.count(value))
                {
                    //print(puzzle);
                    uniqValues.insert(value);
                    pathtable.push_back(z);
                    puzzle1 = dfsSimply(puzzle, xSizeBoard, ySizeBoard);
                    if (toNumber(puzzle1) == 0)
                        return puzzle1;
                    else
                        puzzle = doReverseMoves(z, puzzle);
                }
                else
                    puzzle = doReverseMoves(z, puzzle);
            }
            else{
                pathtable.push_back(z);
                break;}
        }
     return puzzle;
    }
//*******************************************
void dfs(vector< vector<int> > &puzzle, const int &xsizePuzzle,const int &ySizePuzzle ){
if(checkCOuldBeResolve(puzzle))
    {
       print(puzzle) ;
       uniqValues.insert(toNumber(puzzle));
       puzzle =  dfsSimply(puzzle, xsizePuzzle, ySizePuzzle);

        print(puzzle);
        savetoFile("dfs");
    }
else
    cout << "Brak rozwiazania" << endl;
}
//*******************************************

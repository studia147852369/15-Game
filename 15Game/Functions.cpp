#include "Functions.h"
#include <vector>


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

    for(int i = 0; i < size; i++) {
        for(int j=0; j < size; j++) {
            //cout << lessThan(puzzle, i, j) << "*" << numOfEl <<"! + ";
            number += (lessThan(puzzle, i, j))*fact(numOfEl--);
        }
        cout << endl;
    }

    return number;
}
vector<char> canMove(vector< vector<int> > const &puzzle,const int &xSizePuzzle, const int &ySizePuzzle ) {
    vector<char> moves;

    for (int i=0; i<ySizePuzzle; i++)
       {

        for (int z=0; z<xSizePuzzle; z++)
    {
        if (puzzle[i][z] == puzzle.size()*puzzle.size())
        {
            if ( i>0 )
            moves.push_back('G');
            if ( z<xSizePuzzle && z>0 )
            moves.push_back('L');
          if( i<ySizePuzzle -1)
                moves.push_back('D');


          if ( z>=0 && z<xSizePuzzle-1)
              moves.push_back('P');
        }
    }
       }
    return moves;
    }

vector< vector<int> > doMoves(char move, vector< vector<int> > puzzle)
{

int temp=0;
for (int i=0; i<puzzle.size(); i++)
{
    if (temp == -1) break;

    for (int z=0; z<puzzle[i].size(); z++)
    {
         //   cout  << "i " << i << " z " << z<<  "move " << move << endl;

        if (puzzle[i][z] == puzzle.size()*puzzle.size())
        {
          if( move == 'G')
            {   temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i-1][z];
                puzzle[i-1][z] = temp;
                temp=-1;
                break;
            }

          if ( move == 'L' )

            {
                temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i][z-1];
                puzzle[i][z-1] = temp;
                temp=-1;
                break;
            }

          if ( move == 'P' )
            {   temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i][z+1];
                puzzle[i][z+1] = temp;
                temp=-1;
                break;
            }
        if ( move == 'D' )
            {   temp = puzzle[i][z];
                puzzle[i][z] = puzzle[i+1][z];
                puzzle[i+1][z] = temp;
                temp=-1;
                break;
            }
        }
    }
}
    return puzzle;

}
vector< vector<int> > doReverseMoves(char move, vector< vector<int> > puzzle)
{
int temp=0;
for (int i=0; i<puzzle.size(); i++)
    {
        if (temp == -1)
            break;

        for (int z=0; z<puzzle[i].size(); z++)
        {
            if (puzzle[i][z] == puzzle.size()*puzzle.size())
            {

            if( move == 'G')
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i+1][z];
                    puzzle[i+1][z] = temp;
                    temp = -1;
                    break;
                }
            if ( move == 'D' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i-1][z];
                    puzzle[i-1][z] = temp;
                    temp = -1;
                    break;
                }
            if ( move == 'L' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i][z+1];
                    puzzle[i][z+1] = temp;
                    temp = -1;
                    break;
                }
            if ( move == 'P' )
                {
                    temp = puzzle[i][z];
                    puzzle[i][z] = puzzle[i][z-1];
                    puzzle[i][z-1] = temp;
                    temp = -1;
                    break;
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
            // count pairs(i, j) such that i appears
            // before j, but i > j.
            if (tempTabele[j] && tempTabele[i] && tempTabele[i] > tempTabele[j] && tempTabele[i] != tempTabele.size())
                inv_count++;
        }
    }
    cout <<"WYNIK :  "<< numberBlank<<   "count  "<<inv_count <<  endl;


    if (puzzle.size() & 1)
        return !(inv_count & 1);

    else     // grid is even
    {
        if (numberBlank & 1)
            return !(inv_count & 1);
        else
            return inv_count & 1;
    }
}

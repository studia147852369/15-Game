#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef uint64_t U64;

void print( vector< vector<int> >  const &puzzle){
    cout << "___________________________\n" <<endl;
    for (int x=0; x<puzzle.size(); x++)
    {
        cout << "||";
        int separate = 3;
        for (int y=0; y<puzzle[x].size(); y++)
            {
                cout <<setw(separate) << puzzle[x][y] << "  |";
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

int main() {
    const int xsizePuzzle  = 4;
    const int ySizePuzzle = 4;
    vector< vector<int> > puzzle;
    puzzle.resize(4);

    puzzle[0].push_back(6);
    puzzle[0].push_back(1);
    puzzle[0].push_back(15);
    puzzle[0].push_back(16);

    puzzle[1].push_back(7);
    puzzle[1].push_back(8);
    puzzle[1].push_back(11);
    puzzle[1].push_back(9);

    puzzle[2].push_back(12);
    puzzle[2].push_back(2);
    puzzle[2].push_back(5);
    puzzle[2].push_back(3);

    puzzle[3].push_back(14);
    puzzle[3].push_back(13);
    puzzle[3].push_back(10);
    puzzle[3].push_back(4);

    U64 num = toNumber(puzzle);
    print(puzzle);
    cout << "\n\nZe stanu na ukladanke :\n\n";
    print((toPuzzle(num, xsizePuzzle,ySizePuzzle)));;
    return 0;
}

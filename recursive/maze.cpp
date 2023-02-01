#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
struct Intersection{
    int left;
    int forward;
    int right;
};
class Maze{
private:
    int MazeSize;
    int EXIT;
    Intersection *intsec;
public:
    Maze(char* filename);
    int TraverseMaze(int CurrentPos);
};
Maze::Maze(char* filename)//constructor: read intersection info from filename
{
    ifstream fin;
    fin.open(filename,ios::in|ios::_Nocreate);
    if(!fin)
    {
        cerr<<"Failed to open file:"<<filename<<endl;
        exit(1);
    }
    fin>>MazeSize;//input the number of intersection
    intsec=new Intersection[MazeSize+1];//create intersection array
    for(int i=1;i<=MazeSize;i++)
        fin>>intsec[i].left>>intsec[i].forward>>intsec[i].right;
    fin>>EXIT;//input the exit of maze
    fin.close();
}
int Maze::TraverseMaze(int CurrentPos)
{
    if(CurrentPos>0)
    {
        if(CurrentPos==EXIT)
        {
            cout<<CurrentPos<<" ";
            return 1;
        }
        else if(TraverseMaze(intsec[CurrentPos].left))
        {
            cout<<CurrentPos<<" ";
            return 1;
        }
        else if(TraverseMaze(intsec[CurrentPos].forward))
        {
            cout<<CurrentPos<<" ";
            return 1;
        }
        else if(TraverseMaze(intsec[CurrentPos].right))
        {
            cout<<CurrentPos<<" ";
            return 1;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> boards = {{3, 0, 0, 0, 0, 0, 0, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};


bool isSafetoPlace(int r,int c,int num)
{
    //row
    for(int i=0;i<boards.size();i++)
    {
        if(boards[r][i] == num)
        { 
            return false;
        }
    }
    
    //col
    for(int i=0;i<boards[0].size();i++)
    {
        if(boards[i][c] == num)
        { 
            return false;
        }
    }
    
    //3*3 matrix
    r=(r/3)*3;
    c=(c/3)*3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(boards[r+i][c+j] == num)
            {
                return false;
            }
        }
    }
    //cout<<1<<endl;
    return true;
}
void display()
{
    for(vector<int> &arr:boards)
    {
        for(int ele:arr)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

bool sudokuSolver(int idx)
{
    if (idx == boards.size() * boards[0].size())
    {
        display();
        cout << endl;
        return true;
    }

    int r = idx / boards[0].size();
    int c = idx % boards[0].size();
    bool res = false;

    if (boards[r][c] != 0)
    {
        return sudokuSolver(idx + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafetoPlace(r, c, num))
        {
            boards[r][c] = num;
            res = res || sudokuSolver(idx + 1);
            boards[r][c] = 0;
        }
    }

    return res;
}
void sodokou()
{
    sudokuSolver(0);
}
int main()
{
    sodokou();
    return 0;
}
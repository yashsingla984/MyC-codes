#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;
#define N 9

bool samerowno(int grid[N][N],int &row,int &col,int num)
{
  for(int j=0;j<N;j++)
  {
  
      if(grid[row][j]==num)
        return true;
  }
  return false;
}
bool samecolno(int grid[N][N],int &row,int &col,int num)
{
  for(int j=0;j<N;j++)
  {
      if(grid[j][col]==num)
        return true;
  }
  return false;
}

bool sameboxno(int grid[N][N],int temprow,int tempcol,int num)
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(grid[temprow+i][tempcol+j]==num)
        return true;
    }
  }
  return false;
}
bool isSafe(int grid[N][N],int &row,int &col,int num)
{
  if(samerowno(grid,row,col,num) || samecolno(grid,row,col,num)  || sameboxno(grid,row-row%3,col-col%3,num))
  {
    return false;
  }
  return true;
}

bool findzero(int grid[N][N],int &row,int &col)
{
  for(row=0;row<N;row++)
  {
    for(col=0;col<N;col++)
    {
      if(grid[row][col]==0)
        return true;
    }
  }
  return false;
}


bool Sudoku(int grid[N][N])
{
  int row,col;
  
  if(!findzero(grid,row,col))
    return true;

    for(int num=1;num<=9;num++)
    {
     if(isSafe(grid,row,col,num)) 
     {
      grid[row][col]=num;
      if(Sudoku(grid))
      {
        return true;
      }

      grid[row][col]=0; //wrong num
     }
    }
    
  return false;
}

void print(int grid[N][N])
{
  for(int i=0;i<N;i++)
  {
    cout<<"\n";
    for(int j=0;j<N;j++)
    {
      cout<<grid[i][j]<<"\t";
    }
  }
}

int main()
{
  int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(Sudoku(grid)==true)
    {
      print(grid);
    }
    else
    {
      cout<<"sudoku doesnot exist";
    }

    
    return 0;                  
}
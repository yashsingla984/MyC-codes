#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;
#define N 8

void printknight(int sol[N][N])
{
  cout<<"\n";
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cout<<sol[i][j]<<"\t";
    }
    cout<<"\n";
  }
}

bool isSafe(int nextx,int nexty,int sol[N][N])
{
  if(nextx>=0 && nextx<N && nexty>=0 && nexty<N && sol[nextx][nexty]==-1)
  {
    return true;
  }
  else 
    return false;
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], 
                int xMove[N], int yMove[N]) 
{ 
   int k, next_x, next_y; 
   if (movei == N*N) 
   {
       return 1; 
   }
  
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++) 
   { 
       next_x = x + xMove[k]; 
       next_y = y + yMove[k]; 
       if (isSafe(next_x, next_y, sol)) 
       { 
         sol[next_x][next_y] = movei; 
         if (solveKTUtil(next_x, next_y, movei+1, sol,xMove, yMove) == 1) 
             return 1; 
         else
             sol[next_x][next_y] = -1;// backtracking 
       } 
   } 
  
   return 0; 
} 
int solveKT()
{

  cout<<"in solveKT";
  //int movei=0;
  int sol[N][N];
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
      sol[i][j]=-1;
  }
  int xMove[]={2, 1, -1, -2, -2, -1,  1,  2 };
  int yMove[]={1, 2,  2,  1, -1, -2, -2, -1};
  sol[0][0]=0;

   if(solveKTUtil(0, 0, 1, sol, xMove, yMove)==0)
    {
      cout<<"No tour exist";
    }
    else
    {
      printknight(sol);
    }

  //int ans=solveknighttour(0,0,1,sol,xmove,ymove);
  //print(sol);

  return 0;
}

int main()
{
  cout<<"in main";
  solveKT();

  
  return 0;
}
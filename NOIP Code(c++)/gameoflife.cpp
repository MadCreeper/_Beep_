#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<bits/stdc++.h>
#define cls() system("cls")
using namespace std;
const int n=100,m=100;
int M[n+10][m+10];
int T[n+10][m+10];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
int good_p,low_p;
void gotoxy( int line, int column )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

void disp()
{
    cls();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(M[i][j]==1)
            {
                gotoxy(i,j);
                putchar('*');
            }
        }
}
void grow()
{
       memcpy(T,M,sizeof(T));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int sum=0;
                for(int k=0;k<8;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if(M[x][y]==1) sum++;
                }

                if(M[i][j]==1)
                {
                    if(sum>good_p || sum<low_p) T[i][j]=0;
                }

                if(M[i][j]==0)
                {
                    if(sum==good_p) T[i][j]=1;
                }
            }
        }
        memcpy(M,T,sizeof(M));
}
int main()
{
    int sx,sy,cx,cy;
    printf("input good value and lowest value: \n");
    cin>>good_p>>low_p;
    printf("input center x and y: \n");
    cin>>cx>>cy;
    printf("input initial size (m*n) \n");
    cin>>sx>>sy;
    for(int i=cx;i<=cx+sx-1;i++)
        for(int j=cy;j<=cy+sy-1;j++)
        cin>>M[i][j];
    disp();
    Sleep(1000);
    int turn=10,t=1;
    while(t<=turn)
    {
        grow();
        disp();
        Sleep(1000);
        t++;
    }
}

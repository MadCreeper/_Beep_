#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[20];
int yh[15][1000];
bool cmp(int x,int y)
{
    return x>y;
}
bool check()
{
   int ss=0;
   for(int i=1;i<=n;i++)
   {
      ss+=yh[n][i]*a[i];
      if(ss>sum)
      {
          sort(a+i,a+1+n,cmp);
          return 0;
      }

   }
   if(ss==sum)
   {
        return 1;
   }
   return 0;
}
int main()
{
    cin>>n>>sum;
    yh[1][1]=1;
    yh[2][1]=yh[2][2]=1;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
    }


    for(int i=1;i<=n;i++)
        a[i]=i;
    do
    {
        /*for(int i=1;i<=n;i++)
            {
                printf("%d ",a[i]);
            }
            cout<<endl;

    */

       if(check())
       {
           for(int i=1;i<=n;i++)
            {
                printf("%d ",a[i]);
            }

            break;
       }
    }while(next_permutation(a+1,a+n+1));

}

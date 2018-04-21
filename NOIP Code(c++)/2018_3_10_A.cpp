#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[10];
int b[3][10];
int hex(int x,int y)
{
    return x*16+y*1;
}
int p22(int x)
{
    return x*x;
}
char tohex(int x)
{
    if(0<=x && x<10) return '0'+x;
    else return 'a'+x-10;
}
int main()
{
    cin>>s;
    s.erase(s.begin());
    for(int i=0;i<6;i++)
    {
        if(isdigit(s[i])) a[i]=s[i]-'0';
        else a[i]=s[i]-'a'+10;

    }
   b[0][0]=b[0][1]=a[0]; b[0][2]=b[0][3]=a[2]; b[0][4]=b[0][5]=a[4];
   b[1][0]=b[1][1]=a[0]+1; b[1][2]=b[1][3]=a[2]+1; b[1][4]=b[1][5]=a[4]+1;
   b[2][0]=b[2][1]=a[0]-1; b[2][2]=b[2][3]=a[2]-1; b[2][4]=b[2][5]=a[4]-1;
   int minn=99999999,p1,p2,p3;
   for(int i=0;i<3;i++)
   {
       int ans=(p22(hex(a[0],a[1])-hex(b[i][0],b[i][1])));
       if(ans<minn)
       {
           minn=ans;
           p1=i;
       }

   }
   minn=99999999;
      for(int i=0;i<3;i++)
   {
       int ans=(p22(hex(a[2],a[3])-hex(b[i][2],b[i][3])));
       if(ans<minn)
       {
           minn=ans;
           p2=i;
       }

   }
   minn=99999999;
      for(int i=0;i<3;i++)
   {
       int ans=(p22(hex(a[4],a[5])-hex(b[i][4],b[i][5])));
       if(ans<minn)
       {
           minn=ans;
           p3=i;
       }

   }

     cout<<"#"<<tohex(b[p1][0])<<tohex(b[p2][2])<<tohex(b[p3][4]);
}

#include<bits/stdc++.h>
using namespace std;
struct p
{
    int x,y,z;
};
vector<p> m;
void init()
{
   m.push_back((p){1,0,0});
   m.push_back((p){0,1,0});
   m.push_back((p){0,0,1});
   m.push_back((p){1,1,0});
   m.push_back((p){0,1,1});
   m.push_back((p){1,0,1});
   m.push_back((p){1,1,1});
}
int a[100][100][100];
int main()
{
   int T;
   init();
   cin>>T;

   while(T--)
   {
       int n;
       cin>>n;
        cout<<m.size()<<endl;

        for(int i=2;i<=n;i++)
        {
           memset(a,0,sizeof(a));
           for(int j=0;j<m.size();j++)
           {
                for(int k=2;k*m[j].x<=n;k++)
                {
                    cout<<j<<" "<<k*m[j].x<<" "<<k*m[j].y<<" "<<k*m[j].z<<endl;
                    a[k*m[j].x][k*m[j].y][k*m[j].z]=1;
                }

           }

          m.clear();
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    for(int k=0;k<=n;k++)
                    {
                        if(a[i][j][k]==0) m.push_back((p){i,j,k});
                        printf("%d %d %d\n",i,j,k);
                    }
          cout<<m.size()-1<<endl;
        }
   }

}

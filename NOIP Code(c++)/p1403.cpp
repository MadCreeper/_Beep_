#include<bits/stdc++.h>
using namespace std;
int s[1000000+5];
int main()
{
    int n;
    cin>>n;
    freopen("out.txt","w",stdout);
    for(int i=1;i<=n;i++)
    {
        //int t=0;
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0) s[i]+=2;
            if(j*j==i) s[i]--;
        }
        printf("%d,",s[i]);
    }

}

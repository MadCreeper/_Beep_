#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int sum;
    for(int i=1;i<=a/2;i++)
        for(int j=i;j<=a;j++)
        {
            sum=(i+j)*(j-i+1);
            if( sum==2*a ) cout<<i<<" "<<j<<endl;
            if(sum>2*a) break;
        }
}

#include<bits/stdc++.h>
using namespace std;
int dp[100000+10];
int n,k,p=100003;
int main(){
    cin>>n>>k;
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
           if((i-j)>=0) dp[i]+=dp[i-j];
           dp[i]%=p;
        }

    }
    cout<<dp[n]%p<<" ";
}

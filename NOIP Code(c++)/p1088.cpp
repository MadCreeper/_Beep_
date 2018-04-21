#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        next_permutation(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";

}



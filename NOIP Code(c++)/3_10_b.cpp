#include<iostream>
#define LL long long
using namespace std;
LL a[]={0,1,4,27,256,3125,46656,823543,16777216,387420489,10000000000,285311670611,8916100448256,302875106592253,11112006825558016,437893890380859375};
int main(){
    LL n;
    while(cin>>n)
    {
        LL ans=0;
        for(int i=1;i<=15;i++)
        {
            if(n<a[i]) break;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;
int main()
{
   priority_queue< int,vector<int>,greater<int> > pq;
   int n;
    while(true)
    {
        scanf("%d",&n);

        int ans=0;
        int t;
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            pq.push(t);
        }
        int a,b;
        while(pq.size()>1)
        {
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        int cost=a+b;
        ans+=cost;
        pq.push(cost);
        }
        cout<<ans<<endl;
        pq.pop();
    }

}


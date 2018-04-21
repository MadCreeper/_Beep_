#include<bits/stdc++.h>
using namespace std;
int main()
{
   vector<int> a;
   for(int i=1;i<=10;i++)
        a.push_back(i);
   a.erase(a.begin()+1,a.begin()+5);

   for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";

}


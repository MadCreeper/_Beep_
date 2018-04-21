#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> a;
    a.push_back("fack");
    a.insert(a.begin()+1,5,"you");
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<endl;
}

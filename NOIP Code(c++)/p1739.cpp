#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> m;
int main()
{
    cin>>s;
    int k1=0,k2=0;
    bool flag=1;
    for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') m.push(1);
            if(s[i]==')')
            {
                if(m.empty())
                {
                    flag=0;
                    break;
                }
                m.pop();
            }
        }
        if(!m.empty()) flag=0;

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}

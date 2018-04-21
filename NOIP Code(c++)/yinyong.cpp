#include<bits/stdc++.h>
using namespace std;
//int a[3]={1,2,3};
int main()
{
    vector<int> a;
    a.push_back(5);
    int &p=a[0];
    p=166;
    cout<<a[0];
}

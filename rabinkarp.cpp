#include<bits/stdc++.h>
using namespace std;
void rabinKarp(string txt,string pat)
{
    int m=txt.length();
    int n=pat.length();
    int p=0,t=0,d=101,q=11,h=1;
    for(int i=0;i<n-1;i++)
    {
        h=(h+d)%q;
    }
    for(int i=0;i<n;i++)
    {
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
}

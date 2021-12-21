//recursive approach for LCS
#include<bits/stdc++.h>
using namespace std;
int lcsRecursive(string str1,string str2,int m,int n)
{
    if(m==0||n==0)
    {
        return 0;
    }
    if(str1[m-1]==str2[n-1])
    {
        return 1+lcsRecursive(str1,str2,m-1,n-1);
    }
    else
    {
        return max(lcsRecursive(str1,str2,m,n-1),lcsRecursive(str1,str2,m-1,n));
    }
}
int lcsDP(string str1,string str2,int m,int n)
{
    int sol[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                sol[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                sol[i][j]=sol[i-1][j-1]+1;
            }
            else
            {
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
            }
        }
    }
    return sol[m][n];
}
int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int m=str1.length();
    int n=str2.length();
    int result1=lcsRecursive(str1,str2,m,n);
    cout<<"using recursive: "<<result1<<endl;
    int result2=lcsDP(str1,str2,m,n);
    cout<<"using DP: "<<result2<<endl;
    return 0;
}

/*

sample input:-

agctggctagttcag
gtgcatgtcgtta

Output:-

using recursive: 9
using DP: 9

*/
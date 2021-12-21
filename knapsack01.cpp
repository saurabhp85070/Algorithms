#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int value[],int n,int k)
{
    int i,j;
    int sol[n+1][k+1];
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<k+1;j++)
        {
            if(i==0||j==0)
            {
                sol[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                sol[i][j]=sol[i-1][j];
            }
            else
            {
                sol[i][j]=max(sol[i-1][j],value[i-1]+sol[i-1][j-wt[i-1]]);
            }
        }
    }
    return sol[n][k];
}
int main()
{
    int n,capacity;
    cin>>n>>capacity;
    int wt[n],value[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>value[i];
    }
    int result=knapsack(wt,value,n,capacity);
    cout<<result;
}

/*
sample input:-

4 50
20 100
60 300
50 500
2 40

Output:-

500

*/
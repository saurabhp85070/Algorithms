// implementing topological sort

#include<bits/stdc++.h>
using namespace std;
void topologicalUtils(vector<int>graph[],bool visited[],stack<int>&s,int i)
{
    visited[i]=true;
    int n=graph[i].size();
    for(int j=0;j<n;j++)
    {
        if(!visited[graph[i][j]])
        {
            topologicalUtils(graph,visited,s,graph[i][j]);
        }
    }
    s.push(i);
}
void topologicalSort(vector<int>graph[],int v)
{
    bool visited[v];
    stack<int>s;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            topologicalUtils(graph,visited,s,i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int v,e,s,d;
    cin>>v>>e;
    vector<int>graph[v];
    for(int i=0;i<e;i++)
    {
        cin>>s>>d;
        graph[s].push_back(d);
    }
    topologicalSort(graph,v);
    return 0;
}

/*
sample input:- 

6 6
0 1
0 2
0 3
2 3
2 5
4 5

Output:-         

4 0 2 5 3 1

*/
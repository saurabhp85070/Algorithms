// implementing bellman ford algo
#include<bits/stdc++.h>
using namespace std;
//const int INF=1e9;
void path(vector<int>&parent,int j)
{
    if(parent[j]==-1)
    {
        cout<<j;
        return;
    }
    cout<<j<<" <- ";
    path(parent,parent[j]);
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges;
    vector<int>dist(n+1,1e9);
    vector<int>parent(n+1,-1);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    int src;
    cin>>src;
    dist[src]=0;
    bool negative_cycle;
    for(int it=1;it<n;it++)
    {
        negative_cycle=false;
        for(auto e: edges)
        {
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
                negative_cycle=true;
            }
        }
    }
    if(negative_cycle)
    {
        cout<<"negative cycle present";
    }
    else
    {
        for(int i=1;i<n+1;i++)
        {
            path(parent,i);
            cout<<" : "<<dist[i]<<endl;
        }
    }
    return 0;
}

/*
sample input:-

5 6
1 2 4
2 3 2
3 1 1
2 5 4
3 4 4
4 5 4
1

Output:-

1 : 0
2 <- 3 <- 1 : 3
3 <- 1 : 1     
4 <- 3 <- 1 : 5
5 <- 2 <- 3 <- 1 : 7

*/
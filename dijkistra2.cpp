// implementing dijkistra along with info
#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
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
    int n,m; // n=vertex,m=edges
    cin>>n>>m;
    vector<int>dist(n+1,inf);
    vector<int>parent(n+1,-1);
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w}); // remove this line in case of directed graph
    }
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>>s;
    //{weight,vertex}
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:graph[x.second])
        {
            if(dist[it.first]>dist[x.second]+it.second)
            {
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
                parent[it.first]=x.second;
            }
        }
    }
    /* below block will print only dist of source to all other nodes
     for(int i=1;i<=n;i++)
     {
         if(dist[i]<inf)
         {
             cout<<dist[i]<<" ";
         }
         else
         {
             cout<<-1<<" ";
         }
     }
     */
    for(int i=1;i<n+1;i++)
    {
        path(parent,i);
        cout<<" = "<<dist[i]<<endl;
    }
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

1 = 0
2 <- 3 <- 1 = 3
3 <- 1 = 1
4 <- 3 <- 1 = 5
5 <- 2 <- 3 <- 1 = 7

*/
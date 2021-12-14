// implementing kruskal algo

#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>>vii;
int find(int u,int *parent)
{
    if(parent[u]<0)
    {
        return u;
    }
    return find(parent[u],parent);
}
void unionByWeight(int u,int v,int *parent)
{
    int pu=find(u,parent);
    int pv=find(v,parent);
    if(pu!=pv)
    {
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }   
}
vii kruskal(vii g,int v)
{
    vii res;
    int s,d,w;
    int parent[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
    }
    int E=g.size();
    sort(g.begin(),g.end());
    for(int i=0;i<E;i++)
    {
        s=g[i].second.first;
        d=g[i].second.second;
        w=g[i].first;
        if(find(s,parent)!=find(d,parent))
        {
            res.push_back(g[i]);
            unionByWeight(s,d,parent);
        }
    }
    return res;
}
int main()
{
    vii res,g;
    int s,d,w,E,V;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
    res=kruskal(g,V);
    int sum=0;
    for(int i=0;i<res.size();i++)
    {
        int w=res[i].first;
        cout<<res[i].second.first<<" "<<res[i].second.second<<endl;
        sum+=w;
    }
    cout<<"sum of weights: "<<sum<<endl;
}
/*
sample input:-

9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
8 2 2
6 8 6
5 2 4
3 5 14
7 0 8
7 1 7
6 7
5 6
8 2
0 1
5 2
2 3
7 1
3 4

Output:-

sum of weights: 36

*/

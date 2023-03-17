#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int disc[N],low[N],vis[N],par[N];
vector<pair<int,int>>bridges;
void dfs(int node, int &time)
{
    disc[node]=low[node]=time++;
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            par[child]=node;
            dfs(child,time);
            low[node]=min(low[node],low[child]);
            if(low[child]>disc[node]){
                bridges.push_back({node,child});
            }
        }else if(child!=par[node]){
            low[node]=min(low[node],disc[child]);
        }
    }
}
int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int time=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            dfs(i,time);
        }
    }
    for(auto it:bridges){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}

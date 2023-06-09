#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int AP[N],disc[N],low[N],vis[N];
void dfs(int node, int par, int &time)
{
    int children=0;
    disc[node]=low[node]=time++;
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            children++;
            dfs(child,node,time);
            low[node]=min(low[node],low[child]);
            if(par!=-1&&low[child]>=disc[node])AP[node]=1;
        }else if(par!=-1){
            low[node]=min(low[node],disc[child]);
        }
    }
    if(par==-1&&children>1)AP[node]=1;
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
            dfs(i,-1,time);
        }
    }
    for(int i=1;i<=n;i++){
        if(AP[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}

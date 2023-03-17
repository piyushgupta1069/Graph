#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int disc[N],low[N],inStack[N];
vector<vector<int>>scc;
stack<int>st;
void dfs(int node, int &time)
{
    disc[node]=low[node]=time++;
    st.push(node);
    inStack[node]=1;
    for(auto child:adj[node])
    {
        if(!disc[child])
        {
            dfs(child,time);
            low[node]=min(low[node],low[child]);
        }else if(inStack[child]){
            low[node]=min(low[node],disc[child]);
        }
    }
    if(low[node]==disc[node])
    {
        vector<int>temp;
        while(st.top()!=node){
            temp.push_back(st.top());
            inStack[st.top()]=0;
            st.pop();
        }
        temp.push_back(st.top());
        inStack[st.top()]=0;
        st.pop();
        scc.push_back(temp);
    }
}
int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    int time=1;
    for(int i=1;i<=n;i++)
    {
        if(!disc[i]){
            dfs(i,time);
        }
    }
    for(auto it:scc){
        for(auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
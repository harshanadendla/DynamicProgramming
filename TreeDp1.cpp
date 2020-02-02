#include<bits/stdc++.h>
using namespace std;

int n;
int points[100100];
vector<int> graph[100100];
int incDp[100100];
int excDp[100100];

void addEdge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u,int parent=-1)
{
    incDp[u]+=points[u];
    for(int i : graph[u])
    {
        if(i!=parent)
        {
            incDp[u]+=excDp[i];
            excDp[u]+=max(incDp[i],excDp[i]); // this is where negative point nodes are eliminated.
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>points[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        addEdge(u,v);
    }

    dfs(1);

    cout<<max(incDp[1],excDp[1])<<"\n";
    return 0;
}
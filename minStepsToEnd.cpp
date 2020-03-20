#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5;
const int mod=1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    int k;

    cin>>s>>k;

    int n=s.size();

    vector<bool> vis(n,false);

    queue<pii> q;

    int i=0;
    vis[0]=true;

    if(i+1<n && s[i+1]=='1') q.push(mp(i+1,1)),vis[i+1]=true;
    if(i+2<n && s[i+2]=='1') q.push(mp(i+2,1)),vis[i+2]=true;
    if(i+k<n && s[i+k]=='1') q.push(mp(i+k,1)),vis[i+k]=true; 

    while(!q.empty())
    {
        auto p=q.front();
        q.pop();

        int i=p.f;

        if(i==n-1)
        {
            cout<<p.s;
            return 0;
        }

        if(i+1<n && s[i+1]=='1' && !vis[i+1]) q.push(mp(i+1,p.s+1)),vis[i+1]=true;
        if(i+2<n && s[i+2]=='1' && !vis[i+2]) q.push(mp(i+2,p.s+1)),vis[i+2]=true;
        if(i+k<n && s[i+k]=='1' && !vis[i+k]) q.push(mp(i+k,p.s+1)),vis[i+k]=true; 
    }

    cout<<-1;

    return 0;
}
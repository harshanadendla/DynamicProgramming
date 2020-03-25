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
#define mem(u,v) memset(u,v,sizeof(u))
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,w;
    cin>>n;
    vpii a(n);

    for(int i=0;i<n;i++) cin>>a[i].f;
    for(int i=0;i<n;i++) cin>>a[i].s;

    cin>>w;

    int dp[n+1][w+1];
    mem(dp,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(a[i-1].s>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max( dp[i-1][j] , a[i-1].f+dp[i-1][j-a[i-1].s]);
        }
    }

    cout<<dp[n][w];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}
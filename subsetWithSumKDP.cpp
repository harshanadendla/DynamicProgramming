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

    int n,sum;
    cin>>n>>sum;

    int a[n];
    bool dp[n+1][sum+1];
    memset(dp,0,sizeof dp);

    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<=n;i++) dp[i][0]=true;
    for(int i=1;i<=sum;i++) dp[0][i]=false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j] = (j < a[i-1]) ? dp[i-1][j] : (dp[i-1][j] || dp[i-1][j-a[i-1]]) ; 
        }
    }

    cout<<dp[n][sum];

    return 0;
}
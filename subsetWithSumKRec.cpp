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

int a[N],dp[100][100];

int solve(int n,int sum)
{
    if(dp[n][sum]!=-1) return dp[n][sum];

    if(n==-1) return dp[n][sum]=(sum==0);

    if(sum==0) return dp[n][sum]=1;

    if(a[n]>sum) return dp[n][sum]=solve(n-1,sum);

    return dp[n][sum]=(solve(n-1,sum) || solve(n-1,sum-a[n]));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp,-1,sizeof dp);

    int n,sum;
    cin>>n>>sum;

    for(int i=0;i<n;i++) cin>>a[i];

    cout<<solve(n-1,sum);

    return 0;
}
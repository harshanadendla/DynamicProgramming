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

int solve(int p[],int n)
{
    int m[n][n];
    for(int i=1;i<n;i++) m[i][i]=0;

    for(int l=2;l<n;l++)
    {
        for(int i=1,j=l;j<n;i++,j++)
        {
            m[i][j]=LLONG_MAX;

            for(int k=i;k<j;k++)
            {
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }

    return m[1][n-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int p[n];
    for(int i=0;i<n;i++) cin>>p[i];

    cout<<solve(p,n);

    return 0;
}
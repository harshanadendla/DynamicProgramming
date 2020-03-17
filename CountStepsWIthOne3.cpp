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

int countStepsWithOne3(int n)
{
    int includes[n+1]={0},not_includes[n+1]={0};

    includes[3]=1;
    not_includes[1]=1;
    not_includes[2]=2;
    not_includes[3]=3;

    for(int i=4;i<=n;i++)
    {
        includes[i]=includes[i-1]+includes[i-2]+not_includes[i-3];
        not_includes[i]=not_includes[i-1]+not_includes[i-2];
    }

    return includes[n];
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

    cout<<countStepsWithOne3(n);

    return 0;
}
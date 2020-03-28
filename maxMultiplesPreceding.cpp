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

int divs[N];

void updateFactors(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
            {
                divs[i]++;
            }
            else
            {
                divs[i]++;
                divs[n/i]++;
            }
        }
    }
}

int countFactors(vi a)
{
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        ans=max(ans,divs[a[i]]);
        updateFactors(a[i]);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,t;
    cin>>n;
    vi a;

    for(int i=0;i<n;i++)
    {
        cin>>t;
        a.pb(t);
    }

    cout<<countFactors(a)<<"\n";

    return 0;
}

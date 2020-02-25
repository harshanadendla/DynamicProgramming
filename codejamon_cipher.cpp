#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
const int N=5e5;
const int mod=1e9+7;

int n,m,t,q;
string s;
unordered_map<string,int> hashy;
vector<string> dict;
int dp[N];

int solve(int idx)
{
    if(idx==m) return 1;
    if(dp[idx]!=-1) return dp[idx];

    int res=0;
    for(int i=idx;i<m;i++)
    {
        string temp=s.substr(idx,i-idx+1);
        sort(temp.begin(),temp.end());
        if(hashy.find(temp) != hashy.end())
        {
            res+=(hashy[temp]*solve(i+1))%mod;
        }
    }
    dp[idx]=res;
    return dp[idx]%mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>q;

        dict.clear();
        hashy.clear();

        for(int i=0;i<n;i++)
        {
            cin>>s;
            dict.pb(s);
            string temp=s;
            sort(temp.begin(),temp.end());
            hashy[temp]++;
        }

        cout<<"Case #"<<p<<": ";
        while(q--)
        {
            cin>>s;
            m=s.size();
            for(int i=0;i<m;i++) dp[i]=-1;
            cout<<solve(0)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
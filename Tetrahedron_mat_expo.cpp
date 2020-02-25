#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>
const int N=1e7+7;
const int mod=1e9+7;

vvi identity(int n)
{
    vvi res(n,vi(n,0));
    for(int i=0;i<n;i++)
    {
        res[i][i]=1;
    }
    return res;
}

vvi multiply(vvi a,vvi b)
{
    vvi c(a.size(),vi(b[0].size(),0));
    int x=a.size();
    int y=a[0].size();
    int z=b[0].size();

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<z;j++)
        {
            c[i][j]=0;
            for(int k=0;k<y;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j])%mod;
            }
        }
    }

    return c;
}

vvi solve(vvi res,int n)
{
    if(n==0) return identity(res.size());
    auto a=solve(res,n/2);
    auto ans=multiply(a,a);
    if(n%2) ans=multiply(ans,res);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vvi matrix={{2,1},{3,0}};

    vvi res=solve(matrix,n);

    vvi ans={{0},{1}};
    ans=multiply(res,ans);

    cout<<ans[1][0];
    return 0;
}
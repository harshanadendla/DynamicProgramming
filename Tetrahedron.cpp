// sarigga alochinchu.

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e7+7;
const int mod=1e9+7;

int dp[2][N];

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    int n;
    cin>>n;

    dp[1][0]=1;
    for(int steps=1;steps<=n;steps++)
    {
        dp[1][steps]=(3*dp[0][steps-1])%mod;
        dp[0][steps]=(2*dp[0][steps-1]+dp[1][steps-1])%mod;
    }
    cout<<dp[1][n]<<"\n";

    return 0;
}

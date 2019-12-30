int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) 
{
    int maxEle=INT_MIN;
    for(int i=0;i<a.size();i++) if(a[i]>maxEle) maxEle=a[i] ;
    vector<int> costs(maxEle+1,INT_MAX);
    costs[0]=0;
    for(int j=0;j<b.size();j++)
    {
        int denom=b[j];
        for(int i=1;i<=maxEle;i++)
        {
            if(denom<=i)
            {
                if(costs[i-denom]!=INT_MAX)
                {
                    costs[i]=min(costs[i],costs[i-denom]+c[j]);
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<a.size();i++)
    {
        res+=costs[a[i]];
    }
    return res;
}
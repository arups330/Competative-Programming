#include<bits/stdc++.h>
using namespace std;
int z;
void solve()
{
    int n,k,i;
    cin>>n>>k;
    ++n;
    ++k;
    int a[n],sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int low=0,high=sum,mid;
    int j;
    while(low<=high)
    {
        mid=(low+high)/2;
        for(i=1,j=0;i<=k;i++)
        {
            sum=0;
            for(;j<n;j++)
            {
                if(sum+a[j]>mid)break;
                sum+=a[j];
            }
        }
        if(j<n)low=mid+1;
        else high=mid-1;
    }
    cout<<"Case "<<z<<": "<<low<<endl;

    for(i=0,j=0;i<k;i++)
    {
        int sum=0;
        for(;j<n;j++)
        {
            if(sum+a[j]>low)break;
            sum+=a[j];
        }
        cout<<sum<<endl;
    }

}
signed main()
{
    int t;
    cin>>t;
    for(z=1;z<=t;z++)
        solve();
    return 0;
}

#include<bits/stdc++.h>
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int z;
void solve()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    ++n;
    ++k;
    int a[n],sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
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
    printf("Case %d: %d\n",z,low);
    //cout<<"Case "<<z<<": "<<low<<endl;

    for(i=k,j=0;i>0;i--)
    {
        int sum=0;
        for(;i+j<=n;j++)
        {
            if(sum+a[j]>low)break;
            sum+=a[j];
        }
        printf("%d\n",sum);
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
        solve();
    return 0;
}
